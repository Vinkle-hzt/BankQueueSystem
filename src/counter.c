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
    ct->kpi.customers_num++;

    // log
    show_date(log_file, get_cur_date());
    printf(" (ID: %d 姓名: %s) 分配至柜台 %d\n",
           customer->ID, customer->name, ct->number);
}

void show_counter_customer()
{

}