/**
 * @file counter.c
 * @brief 柜台类及相关操作
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "counter.h"

array_list *create_counter(int num)
{
    array_list *counters = al_create(NULL);

    for (int i = 0; i < num; i++)
    {
        counter *cur = malloc(sizeof(counter));
        cur->customer = NULL;
        cur->number = i + 1;
        cur->kpi = trade_conclude_create();
        al_push(counters, cur);
    }

    return counters;
}

void counter_assign_customer(counter *ct, member *customer)
{
    cur_call_num[customer->vip]++;
    ct->customer = customer;
    ct->customer->come_time = time(0);

    // 分配柜台
    show_date(log_file, get_cur_date());
    fprintf(log_file, " (ID: %d 姓名: %s) 分配至柜台 %d\n",
           customer->ID, customer->name, ct->number);
}

void show_counter_customer()
{
    // 判断柜台是否空闲
    for (int i = 0; i < counters->curSize; i++)
    {
        counter *cur_counter = (counter *)al_at(counters, i);
        if (cur_counter->customer != NULL)
            printf("柜台 %d >> ID：%d 姓名：%s 可以办理业务\n", i + 1,
                   cur_counter->customer->ID, cur_counter->customer->name);
        else
            printf("柜台 %d 空闲中\n", i + 1);
    }
}

void member_leave_counter(counter *ct, member *m)
{
    ct->kpi.customers_num++;
    all_trade.customers_num++;
    m->leave_time = time(0);
    ct->kpi.total_time +=  m->leave_time - m->come_time;
    all_trade.total_time += m->leave_time - m->come_time;

    // 日志信息
    show_date(log_file, get_cur_date());
    fprintf(log_file, " (ID: %d 姓名: %s, vip：%d) 离开银行 \n", m->ID, m->name, m->vip);

    safe_free(m);
}
