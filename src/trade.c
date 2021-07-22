#include "trade.h"

void start_trade()
{
    // 选择柜台
    show_counter_customer();
    int counter_num = getchar() - '0';
    fflush(stdin);
    counter* cur_counter = (counter*) al_at(counters, counter_num);
    if (!cur_counter->customer)
        return;
    
    // 选择卡
    card cur_card = choose_card(cur_counter->customer->ID);
    
    // 显示交易菜单
    show_basicbusiness_menu();
    int exit_flag = 0;

    // 交易菜单选择
    while (!exit_flag)
    {
        fflush(stdin);
        show_main_menu();
        char choice = getchar();
        fflush(stdin);
        int flag = 1;
        do
        {
            switch (choice)
            {
            case '1':
                check_banlance(&cur_card);
                break;
            case '2':
                deposit_money(&cur_card);
                break;
            case '3':
                withdraw_money(&cur_card);
                break;
            case '4':
                transfer_accounts(&cur_card);
                break;
            case '5':
                view_transactions(&cur_card);
                break;
            case '0':
                show_exit_message();
                exit_flag = 1;
                break;
            default:
                printf("非法字符，请重新输入！！！\n");
                system("pause");
                break;
            }
        } while (!flag);
    }
}