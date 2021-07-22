/**
 * @file date.c
 * @brief 日期类及相关操作
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "date.h"

date get_cur_date()
{
    date cur;
    time_t timep;
    struct tm *p;
    time (&timep);
    p=gmtime(&timep);
    int plus = 0;

    cur.minute = p->tm_min;
    cur.hour = p->tm_hour;
    cur.day = p->tm_mday;
    cur.month = p->tm_mon;
    cur.year = p->tm_year + 1900;

    return cur;
}

void show_date(FILE* f, date d)
{
    fprintf(f, "[UTC %d/%d/%d %d:%d]", d.year, d.month, d.day, d.hour, d.minute);
}