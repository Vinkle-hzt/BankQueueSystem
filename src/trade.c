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
    // 选择卡
    // card cur_card = choose_card(cur_counter->customer->ID);

    // 显示交易菜单
    show_basicbusiness_menu();
    int exit_flag = 0;

    // // 交易菜单选择
    // while (!exit_flag)
    // {
    //     fflush(stdin);
    //     show_main_menu();
    //     char choice = getchar();
    //     fflush(stdin);
    //     int flag = 1;
    //     do
    //     {
    //         switch (choice)
    //         {
    //         case '1':
    //             check_balance(&cur_card);
    //             break;
    //         case '2':
    //             deposit_money(&cur_card);
    //             break;
    //         case '3':
    //             withdraw_money(&cur_card);
    //             break;
    //         case '4':
    //             transfer_accounts(&cur_card);
    //             break;
    //         case '5':
    //             view_transactions(&cur_card);
    //             break;
    //         case '0':
    //             show_exit_message();
    //             exit_flag = 1;
    //             break;
    //         default:
    //             printf("非法字符，请重新输入！！！\n");
    //             system("pause");
    //             break;
    //         }
    //     } while (!flag);
    // }
}

// void check_balance(card *cur_card)
// {
//     FILE *cards_file = fopen(user_account_file, "r");

//     fclose(cards_file);
// }