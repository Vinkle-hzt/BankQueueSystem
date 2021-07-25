/**
 * @file bank_queue_system.c
 * @brief 银行排队系统相关函数
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "bank_queue_system.h"

void start_system()
{
    // 初始化变量
#ifdef DEBUG
    log_file = stdout;
#else
    log_file = fopen("BankQueueSystem.log", "a");
#endif
    start_mysql();
    waiting_line = pq_create(member_compare);
    counters = create_counter(COUNTER_NUM);
    all_trade = trade_conclude_create();

    // 显示欢迎信息
    show_welcome_message();

    int exit_flag = 0; // 退出菜单标志

    // 显示主菜单
    while (!exit_flag)
    {
        fflush(stdin);
        show_main_menu();
        char choice = getchar();
        fflush(stdin);
#ifndef DEBUG
    system("cls");
#endif
        switch (choice)
        {
        case '1':
            do_pick_number();
            break;
        case '2':
            start_trade();
            break;
        case '3':
            check_all_trade();
            break;
        case '4':
            update_VIP();
            break;
        case '0':
            show_exit_message();
            exit_flag = 1;
            break;
        default:
            printf("\n非法字符，请重新输入！！！\n");
            break;
        }
        system("pause");

#ifndef DEBUG
        system("cls");
#endif
    }

    pq_free(waiting_line);
    al_free(counters);

#ifndef DEBUG
    fclose(log_file);
#endif
}

void do_pick_number()
{
    printf("\n请输入您的 ID 和姓名 (以空格分隔，若要新建用户，请将ID 输为 0):\n");
    int waiting_num = waiting_line->curSize;
    int ID;
    char name[20];
    scanf("%d %s", &ID, name);
    member *cur_customer = member_come(ID, name);

    // 判断 ID 与姓名是否匹配
    if (cur_customer == (member *)&member_error_1)
    {
        printf("ID 与姓名不匹配！！！\n");
        return;
    }

    // 判断 ID 是否存在
    if (cur_customer == (member *)&member_error_2)
    {
        printf("没有此 ID， 请检查您的 ID 号码！！！\n");
        return;
    }

    update_pick(cur_customer);

#ifndef DEBUG
    system("cls");
#endif

    printf("\n欢迎来到银行, %s, 你的总取号码是 %d。\n", name, cur_customer->common_pick_num);
    printf("您是 vip %d，当前会员取号码位 v%d-%d，你可以最多提前 %d 号进入\n",
           cur_customer->vip, cur_customer->vip, cur_customer->vip_pick_num, cur_customer->vip * 3);

    // 查询空柜台
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

    // 如果没有空柜台，进入队列
    if (!serve_flag)
    {
        printf("还未轮到您, 请稍等...\n");
        pq_push(waiting_line, cur_customer);
    }

    printf("\n");
}

int login_admin()
{
    char id[40];
    char pwd[40];

    printf("\n此为**内部**功能，请登录管理员账号...\n");
    printf("账号：");
    scanf("%s", id);
    printf("密码：");
    scanf("%s", pwd);

    uint8_t *pwdmd5 = getMD5(pwd);
    for (int i = 0; i < 16; i++)
        sprintf((pwd + i * 2), "%2.2x", pwdmd5[i]);

    // 判断 ID 与密码是否符合
    sprintf(mysql_buffer, "SELECT * FROM `admin` WHERE(`ID` = \"%s\" AND `password` = \"%s\")", id, pwd);
    mysql_query(&mysql_connect, mysql_buffer);
    mysql_res = mysql_store_result(&mysql_connect);

    free(pwdmd5);

    int row = mysql_num_rows(mysql_res);
    if (row)
        return 1;
    return 0;
}

void check_all_trade()
{
    int admin_enter = 0;
    int login_flag = 0;
    while (admin_enter < 3)
    {
        if (login_admin())
        {
            login_flag = 1;
            break;
        }
        admin_enter++;
        printf("\n 账号或密码错误！！！ 请重新输入 ！！！\n\n");
        system("pause");
#ifndef DEBUG
        system("cls");
#endif
    }
    if (!login_flag)
        printf("登录失败次数太多，请稍后再试\n");
    else
    {
#ifndef DEBUG
        system("cls");
#endif
        printf("\n登录成功 :) 尊敬的管理员\n\n");
        printf("此为银行总交易信息：\n");
        show_trade_conclude(&all_trade);

        for (int i = 0; i < counters->curSize; i++)
        {
            printf("\n此为柜台 %d 的交易信息：\n", i + 1);
            counter *cur_counter = (counter *)al_at(counters, i);
            show_trade_conclude(&cur_counter->kpi);
        }
    }
}

void update_VIP()
{
    printf("\n请输入您的 ID 和姓名 (以空格分隔，若要新建用户，请将ID 输为 0):\n");
    int ID;
    char name[20];
    scanf("%d %s", &ID, name);
    member *cur_customer = member_come(ID, name);

    // 判断 ID 与姓名是否匹配
    if (cur_customer == (member *)&member_error_1)
    {
        printf("ID 与姓名不匹配！！！\n");
        return;
    }

    // 判断 ID 是否存在
    if (cur_customer == (member *)&member_error_2)
    {
        printf("没有此 ID， 请检查您的 ID 号码！！！\n");
        return;
    }

#ifndef DEBUG
    system("cls");
#endif

    printf("\nVIP升级规则为：\n0:现有存款大于0\n");
    printf("1:现有存款大于100000\n2:现有存款大于500000\n\n");

    sprintf(mysql_buffer, "SELECT SUM(money) FROM card WHERE user_ID = %d", ID);
    mysql_query(&mysql_connect, mysql_buffer);
    mysql_res = mysql_store_result(&mysql_connect);
    mysql_next_row = mysql_fetch_row(mysql_res);
    double sum_money = atof(mysql_next_row[0]);
    printf("您目前的VIP等级为：%d\n", cur_customer->vip);
    printf("您目前的总存款为：%lf\n", sum_money);
    printf("正在为您查询. . .\n\n");

    int vip_level = 0;
    if (sum_money >= 500000)
        vip_level = 2;
    else if (sum_money >= 100000)
        vip_level = 1;

    if (cur_customer->vip < vip_level)
    {
        sprintf(mysql_buffer, "update user set vip = %d where user_ID = %d", vip_level, cur_customer->ID);
        mysql_query(&mysql_connect, mysql_buffer);
        printf("您的vip等级已为您升级至%d级\n", vip_level);
    }
    else
    {
        if (cur_customer->vip == 2)
        {
            printf("您已升到最高级！\n");
            return;
        }
        else
        {
            printf("您未达到升级要求！\n");
            return;
        }
    }
}