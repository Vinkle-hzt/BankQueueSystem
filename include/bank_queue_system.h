#pragma once

#include <stdlib.h>
#include "array_list.h"
#include "queue.h"

typedef struct
{
    int customers_num;
    int flowing_water;
} trade_conclude;

typedef struct
{
    int ID;
    char *name;
} member;

typedef struct
{
    int number;
    trade_conclude kpi;
    member *customer;
} counter;

void start_system();

array_list *create_counter(int num);
