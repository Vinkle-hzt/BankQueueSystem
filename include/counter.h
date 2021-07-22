#pragma once

#include "member.h"
#include "trade_conclude.h"

typedef struct
{
    int number;
    trade_conclude kpi;
    member *customer;
} counter;

array_list *create_counter(int num);

void counter_come_customer(counter* ct, member* customer);