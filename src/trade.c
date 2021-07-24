#include "trade.h"

void start_trade()
{
    // 选择柜台
    show_counter_customer();

    printf("请输入办理业务的柜台号：");
    int counter_num;
    scanf("%d", &counter_num);
    fflush(stdin);

    if (counter_num > counters->curSize || counter_num <= 0)
    {
        printf("无效柜台号！！！\n");
        return;
    }

    counter *cur_counter = (counter *)al_at(counters, counter_num - 1);

    if (!cur_counter->customer)
    {
        printf("该柜台没有客户！！！\n");
        return;
    }

    int choose_card = -1;

    while (true)
    {
        printf("\n尊敬的%s，", cur_counter->customer->name);
        int cards_num = show_cards(cur_counter->customer->ID);

        if (cards_num == 0)
        {
            printf("您没有卡，输入 0 进行办卡，输入其他结束业务办理：");
            scanf("%d", &choose_card);
            if (choose_card != 0)
            {
                end_trade(cur_counter);
                return;
            }
            else
                create_card(cur_counter->customer->ID);
        }
        else
        {
            printf("请输入办理业务的卡号（输入 0 进行办卡，输入其他卡号结束业务办理）：");
            scanf("%d", &choose_card);
            if (choose_card != 0)
            {
                // 检查卡号是否正确
                int flag = check_card(choose_card, cur_counter->customer->ID);
                if (flag)
                    break;
                else
                {
                    end_trade(cur_counter);
                    return;
                }
            }
            else
                create_card(cur_counter->customer->ID);
        }
    }

    // 显示交易菜单
    int exit_flag = 0;

    // 交易菜单选择
    while (!exit_flag)
    {
        fflush(stdin);
        show_basicbusiness_menu();
        char choice = getchar();
        fflush(stdin);
        int flag = 1;
        do
        {
            switch (choice)
            {
            case '1':
                check_balance(choose_card);
                break;
            case '2':
                deposit_money(choose_card);
                break;
            case '3':
                withdraw_money(choose_card);
                break;
            case '4':
                transfer_accounts(choose_card);
                break;
            case '5':
                view_transactions(choose_card);
                break;
            case '0':
                end_trade(cur_counter);
                exit_flag = 1;
                break;
            default:
                printf("非法字符，请重新输入！！！\n");
                break;
            }
            system("pause");
        } while (!flag);
    }
}

int show_cards(int ID)
{
    sprintf(mysql_buffer, "SELECT card_ID, money FROM `card` WHERE user_ID = %d", ID);
    mysql_query(&mysql_connect, mysql_buffer);
    mysql_res = mysql_store_result(&mysql_connect);
    int row = mysql_num_rows(mysql_res);
    if (row)
    {
        printf("您有 %d 张卡：\n", row);
        for (int i = 0; i < row; i++)
        {
            mysql_next_row = mysql_fetch_row(mysql_res);
            printf("卡号：%s, 金额：%s\n", mysql_next_row[0], mysql_next_row[1]);
        }
    }
    return row;
}

void check_balance(int card_ID)
{
    sprintf(mysql_buffer, "SELECT money FROM card WHERE card_ID = %d", card_ID);
    mysql_query(&mysql_connect, mysql_buffer);
    mysql_res = mysql_store_result(&mysql_connect);
    mysql_next_row = mysql_fetch_row(mysql_res);
    printf("\n卡号：%d，余额：%s\n", card_ID, mysql_next_row[0]);
}

void deposit_money(int card_ID)
{
    double card_deposit = 0;
    printf("请输入您要存款的钱数：\n");
    scanf("%lf", &card_deposit);
    sprintf(mysql_buffer, "update card set money = money + %lf where card_ID = %d", card_deposit, card_ID);
    mysql_query(&mysql_connect, mysql_buffer);
    check_balance(card_ID);
}

void withdraw_money(int card_ID)
{
    double card_withdraw = 0;
    printf("请输入您要取款的钱数：\n");
    scanf("%lf", &card_withdraw);

    //查询卡内余额
    sprintf(mysql_buffer, "SELECT money FROM card WHERE card_ID = %d", card_ID);
    mysql_query(&mysql_connect, mysql_buffer);
    mysql_res = mysql_store_result(&mysql_connect);
    mysql_next_row = mysql_fetch_row(mysql_res);
    double now_money = atof(mysql_next_row[0]);
    if (now_money < card_withdraw)
    {
        printf("您的余额不足！！！\n");
        return;
    }

    //取款过程
    sprintf(mysql_buffer, "update card set money = money - %lf where card_ID = %d", card_withdraw, card_ID);
    mysql_query(&mysql_connect, mysql_buffer);
    check_balance(card_ID);
}

void transfer_accounts(int card_ID)
{
    double card_transfer = 0;
    int card_IDout = 0;
    printf("请输入您要转账的 ID 与 钱数（以空格分隔）：\n");
    scanf("%d %lf", &card_IDout, &card_transfer);

    //查询卡内余额
    sprintf(mysql_buffer, "SELECT money FROM card WHERE card_ID = %d", card_ID);
    mysql_query(&mysql_connect, mysql_buffer);
    mysql_res = mysql_store_result(&mysql_connect);
    mysql_next_row = mysql_fetch_row(mysql_res);
    double now_money = atof(mysql_next_row[0]);
    if (now_money < card_transfer)
    {
        printf("您的余额不足！！！\n");
        return;
    }

    //查询对方账户是否存在
    sprintf(mysql_buffer, "SELECT * FROM card WHERE card_ID = %d", card_IDout);
    mysql_query(&mysql_connect, mysql_buffer);
    mysql_res = mysql_store_result(&mysql_connect);
    int row = mysql_num_rows(mysql_res);
    if( !row )
    {
        printf("没有此账户！！！\n");
        return;
    }

    //转账过程
    sprintf(mysql_buffer, "update card set money = money - %lf where card_ID = %d", card_transfer, card_ID);
    mysql_query(&mysql_connect, mysql_buffer);
    sprintf(mysql_buffer, "update card set money = money + %lf where card_ID = %d", card_transfer, card_IDout);
    mysql_query(&mysql_connect, mysql_buffer);
    check_balance(card_ID);
}

void view_transactions(int card_ID)
{

}

void end_trade(counter *ct)
{
    printf("\n欢迎下次光临 :)\n");
    member_leave(ct->customer);
    ct->customer = NULL;
    call_next(ct);
}

void create_card(int ID)
{
    sprintf(mysql_buffer, "INSERT INTO card (user_ID, money) VALUES (%d, 0)", ID);
    mysql_query(&mysql_connect, mysql_buffer);

    sprintf(mysql_buffer, "SELECT MAX(card_ID) FROM `card`");
    mysql_query(&mysql_connect, mysql_buffer);
    mysql_res = mysql_store_result(&mysql_connect);
    mysql_next_row = mysql_fetch_row(mysql_res);

    printf("您的卡（卡号 %s）办理成功！！！\n", mysql_next_row[0]);
    fflush(stdin);
    system("pause");
}

int check_card(int card_ID, int user_ID)
{
    sprintf(mysql_buffer,
            "SELECT * FROM card WHERE(card_ID = %d AND user_ID = %d)",
            card_ID, user_ID);
    mysql_query(&mysql_connect, mysql_buffer);
    mysql_res = mysql_store_result(&mysql_connect);

    return mysql_num_rows(mysql_res);
}

void call_next(counter* ct)
{
    if (waiting_line->curSize)
    {
        member* customer = (member*)pq_top(waiting_line);
        counter_assign_customer(ct, customer);
        printf("请 v%d-%d 到柜台 %d 办理业务！\n", ct->customer->vip, ct->customer->vip_pick_num, ct->number);
        pq_pop(waiting_line);
    }
}