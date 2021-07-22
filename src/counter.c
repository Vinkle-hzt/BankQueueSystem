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
    cur_call_num++;
    ct->customer = customer;
    ct->kpi.customers_num++;

    // log
    show_date(log_file, get_cur_date());
    printf(" (ID: %d name: %s) can enter the counter %d\n",
           customer->ID, customer->name, ct->number);
}