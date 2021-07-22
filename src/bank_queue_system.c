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
    trade_conclude all_trade = trade_conclude_create();
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

void do_pick_number()
{
    printf("请输入您的 ID 和姓名 (以空格分隔):\n");
    int waiting_num = waiting_line->size;
    int ID;
    char name[20];
    scanf("%d %s", &ID, name);
    member *cur_customer = member_come(ID, name);

    printf("欢迎来到银行, %s, 你的取号是 %d\n", name, cur_pick_num);

    // check spare counter
    int serve_flag = 0;
    if (waiting_num == 0)
    {
        for (int i = 0; i < counters->curSize; i++)
        {
            counter *cur_counter = (counter *)al_at(counters, i);
            if (cur_counter->customer == NULL)
            {
                counter_assign_customer(cur_counter, cur_customer);
                printf("柜台 %d 为空, 您可以在这里办理业务.\n", cur_counter->number);
                serve_flag = 1;
                break;
            }
        }
    }

    if (!serve_flag)
    {
        printf("目前呼叫号码是 %d, 请稍等.\n", cur_call_num);
        queue_push(waiting_line, cur_customer);
    }

    printf("\n");
    getchar();
    system("pause");
}