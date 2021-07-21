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

date get_cur_date();

void show_date(FILE* f, date d);
