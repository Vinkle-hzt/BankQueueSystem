#include "bank_queue_system.h"

void start_system()
{
    // init variable
#ifdef DEBUG
    log_file = stdout;
#else
    log_file = fopen("BankQueueSystem.log", "a");
#endif

    waiting_line = queue_create();
    counters = create_counter(4);
    trade_conclude all_trade;
    all_trade.customers_num = 0;
    all_trade.flowing_water = 0;
    // show welcome message

    // show main menu
    int exit_flag = 0;
    while (!exit_flag)
    {
        show_main_menu();
        char choice = getchar();
        int flag = 1;
        do
        {
            switch (choice)
            {
            case '1':
                fflush(stdin);
                do_pick_number();
                break;
            case '2':
                fflush(stdin);

                break;
            case '3':
                fflush(stdin);

                break;
            case '4':
                fflush(stdin);

                break;
            case '0':
                fflush(stdin);

                show_exit_message();
                exit_flag = 1;
                break;
            default:

                break;
            }
        } while (!flag);
    }
}
