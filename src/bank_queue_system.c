#include "bank_queue_system.h"

void start_system()
{
    array_list* counters = create_counter(4);
    queue* waiting_line = queue_create();

    trade_conclude all_trade;
    all_trade.customers_num = 0;
    all_trade.flowing_water = 0;

    
}

array_list* create_counter(int num)
{
    array_list* counters = al_create(NULL);

    for (int i = 0; i < num; i++)
    {
        counter* cur = malloc(sizeof(counter));
        cur->customer = NULL;
        cur->number = i + 1;
        cur->kpi.customers_num = 0;
        cur->kpi.flowing_water = 0;
        al_push(counters, cur);
    }

    return counters;
}

