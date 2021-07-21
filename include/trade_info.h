#pragma once
#include <time.h>
#include <stdio.h>

typedef enum
{
    Deposit
} Trade_type;

typedef struct
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
} date;

typedef struct
{
    date trade_time;
    Trade_type trade_type;
} trade_info;

date get_cur_date();

void show_date(date d);
