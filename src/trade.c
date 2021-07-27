/**
 * @file trade.c
 * @brief 实现交易业务
 * @date 2021-07-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "trade.h"

void start_trade()
{
    // 选择柜台
    printf("\n");
    show_counter_customer();

    printf("\n请输入办理业务的柜台号：");
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
        printf("\n该柜台没有客户！！！\n");
        return;
    }

    int choose_card = -1;

    while (true)
    {
#ifndef DEBUG
        system("cls");
#endif

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

#ifndef DEBUG
    system("cls");
#endif

    int exit_flag = 0; // 退出标志

    // 交易菜单选择
    while (!exit_flag)
    {
        fflush(stdin);
        show_basicbusiness_menu();
        char choice = getchar();
        fflush(stdin);

#ifndef DEBUG
        system("cls");
#endif
        switch (choice)
        {
        case '1':
            check_balance(choose_card);
            break;
        case '2':
            deposit_money(cur_counter, choose_card);
            break;
        case '3':
            withdraw_money(cur_counter, choose_card);
            break;
        case '4':
            transfer_accounts(cur_counter, choose_card);
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
        if (!exit_flag)
        {
            system("pause");
            system("cls");
        }
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
    printf("\n卡号：%d，余额：%.2lf\n\n", card_ID, get_balance(card_ID));
    show_date(log_file, get_cur_date());
    fprintf(log_file, "（卡号：%d）查询到余额为 %.2lf\n", card_ID, get_balance(card_ID));
}

void deposit_money(counter *ct, int card_ID)
{
    double card_deposit = 0;
    double now_money = get_balance(card_ID);
    printf("\n请输入您要存款的钱数：");

    //判断钱数是否为负
    scanf("%lf", &card_deposit);
    if (card_deposit < 0)
    {
        printf("\n输入信息错误，请重新输入！\n");
        return;
    }
    sprintf(mysql_buffer, "update card set money = money + %lf where card_ID = %d",
            card_deposit, card_ID);
    mysql_query(&mysql_connect, mysql_buffer);

    upload_trade(card_ID, Deposit, now_money, now_money + card_deposit, card_ID);

    check_balance(card_ID);

    // 统计交易金额
    all_trade.flowing_water += card_deposit;
    all_trade.total_deposits += card_deposit;
    ct->kpi.total_deposits += card_deposit;
    ct->kpi.flowing_water += card_deposit;

    //生成 log
    show_date(log_file, get_cur_date());
    fprintf(log_file, "(ID：%d, name: %s)于卡（卡号：%d）存款 %.2lf\n",
            ct->customer->ID, ct->customer->name,
            card_ID, card_deposit);
}

void withdraw_money(counter *ct, int card_ID)
{
    double card_withdraw = 0;
    printf("\n请输入您要取款的钱数：");
    scanf("%lf", &card_withdraw);
    // 判断钱数是否为负
    if (card_withdraw < 0)
    {
        printf("\n输入信息错误，请重新输入！\n");
        return;
    }

    double now_money = get_balance(card_ID);
    if (now_money < card_withdraw)
    {
        printf("您的余额不足！！！\n");
        // 生成log
        show_date(log_file, get_cur_date());
        fprintf(log_file, "(ID：%d, name: %s)的卡（卡号：%d）余额不足\n",
                ct->customer->ID, ct->customer->name, card_ID);
        return;
    }

    // 取款过程
    sprintf(mysql_buffer, "update card set money = money - %lf where card_ID = %d",
            card_withdraw, card_ID);
    mysql_query(&mysql_connect, mysql_buffer);

    upload_trade(card_ID, Withdraw, now_money, now_money - card_withdraw, card_ID);

    check_balance(card_ID);

    // 统计交易金额
    all_trade.flowing_water += card_withdraw;
    ct->kpi.flowing_water += card_withdraw;

    // 生成 log
    show_date(log_file, get_cur_date());
    fprintf(log_file, "(ID：%d, name: %s)于卡（卡号：%d）取款 %.2lf\n",
            ct->customer->ID, ct->customer->name,
            card_ID, card_withdraw);
}

void transfer_accounts(counter *ct, int card_ID)
{
    double transfer_money = 0; // 转账金额
    int transfer_card = 0;     // 转账卡号
    printf("\n请输入您要转账的 ID 与 钱数（以空格分隔）：\n");
    scanf("%d %lf", &transfer_card, &transfer_money);

    if (transfer_money < 0)
    {
        printf("\n输入信息错误，请重新输入！\n");
        return;
    }

    if (transfer_money == card_ID)
    {
        printf("\n不能转账给自己！\n");
        return;
    }

    double now_money = get_balance(card_ID); // 当前余额
    if (now_money < transfer_money)
    {
        printf("\n您的余额不足！！！\n");

        // 生成log
        show_date(log_file, get_cur_date());
        fprintf(log_file, "(ID：%d, name: %s)的卡（卡号：%d）余额不足.",
                ct->customer->ID, ct->customer->name, card_ID);
        return;
    }

    // 查询对方账户是否存在
    sprintf(mysql_buffer, "SELECT * FROM card WHERE card_ID = %d", transfer_card);
    mysql_query(&mysql_connect, mysql_buffer);
    mysql_res = mysql_store_result(&mysql_connect);
    int row = mysql_num_rows(mysql_res);
    if (!row)
    {
        printf("没有此账户！！！\n");
        // 生成 log
        show_date(log_file, get_cur_date());
        fprintf(log_file, "(ID: %d, name: %s)无法转账到不存在的账户", ct->customer->ID, ct->customer->name);
        return;
    }

    // 转账过程
    sprintf(mysql_buffer, "update card set money = money - %lf where card_ID = %d",
            transfer_money, card_ID);
    mysql_query(&mysql_connect, mysql_buffer);
    sprintf(mysql_buffer, "update card set money = money + %lf where card_ID = %d",
            transfer_money, transfer_card);
    mysql_query(&mysql_connect, mysql_buffer);

    //生成日志
    upload_trade(card_ID, Transfer, now_money, now_money - transfer_money, transfer_card);

    double tred_now_money = get_balance(transfer_card);
    upload_trade(transfer_card, BeTransferred, tred_now_money, tred_now_money + transfer_money, card_ID);

    check_balance(card_ID);

    // 统计交易金额
    all_trade.flowing_water += transfer_money;
    ct->kpi.flowing_water += transfer_money;

    // 生成 log
    show_date(log_file, get_cur_date());
    fprintf(log_file, "(ID：%d, name: %s)从（卡号：%d）转账 %.2lf至 (卡号：%d)\n",
            ct->customer->ID, ct->customer->name,
            card_ID, transfer_money, transfer_card);
}

void view_transactions(int card_ID)
{
    sprintf(mysql_buffer, "SELECT * FROM `trade` WHERE card_ID = %d", card_ID);
    mysql_query(&mysql_connect, mysql_buffer);
    mysql_res = mysql_store_result(&mysql_connect);

    printf("\n尊敬的用户，您的卡（卡号：%d）交易记录如下：\n", card_ID);
    printf("[       时间        ][交易类型][  交易前余额  ][  交易后余额  ][        备注        ]\n");
    int row = mysql_num_rows(mysql_res);
    for (int i = 0; i < row; i++)
    {
        mysql_next_row = mysql_fetch_row(mysql_res);
        printf("[%8s]", mysql_next_row[3]);
        int t_type = atoi(mysql_next_row[2]);
        if (t_type == Deposit)
            printf("   存款   ");
        if (t_type == Withdraw)
            printf("   取款   ");
        if (t_type == Transfer)
            printf("   转账   ");
        if (t_type == BeTransferred)
            printf("  被转账  ");

        printf("   %-12.2lf    %-12.2lf", atof(mysql_next_row[4]), atof(mysql_next_row[5]));

        if (t_type == Transfer)
            printf("    转入账户 %s", mysql_next_row[6]);
        if (t_type == BeTransferred)
            printf("    从账户 %s 转入", mysql_next_row[6]);
        printf("\n");
    }
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

#ifndef DEBUG
    system("cls");
#endif
    printf("\n您的卡（卡号 %s）办理成功！！！\n\n", mysql_next_row[0]);
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

void call_next(counter *ct)
{
    if (waiting_line->curSize)
    {
        member *customer = (member *)pq_top(waiting_line);
        counter_assign_customer(ct, customer);
        printf("请 v%d-%d 到柜台 %d 办理业务！\n", ct->customer->vip, ct->customer->vip_pick_num, ct->number);
        pq_pop(waiting_line);
    }
}

double get_balance(int card_ID)
{
    sprintf(mysql_buffer, "SELECT money FROM card WHERE card_ID = %d", card_ID);
    mysql_query(&mysql_connect, mysql_buffer);
    mysql_res = mysql_store_result(&mysql_connect);
    mysql_next_row = mysql_fetch_row(mysql_res);
    return atof(mysql_next_row[0]);
}

void upload_trade(int card_ID, enum Trade_type ty,
                  double pre_money, double cur_money, int trade_ID)
{
    date cur_date = get_cur_date();
    sprintf(mysql_buffer,
            "INSERT INTO trade"
            "(card_ID, trade_type, trade_time, pre_money, cur_money, trade_ID)"
            "VALUES(%d, %d, \"%d-%d-%d %d:%d\", %lf, %lf, %d)",
            card_ID, ty,
            cur_date.year, cur_date.month, cur_date.day, cur_date.hour, cur_date.minute,
            pre_money, cur_money, trade_ID);
    mysql_query(&mysql_connect, mysql_buffer);
}
