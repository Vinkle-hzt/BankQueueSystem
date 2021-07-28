/**
 * @file trade_conclude.c
 * @brief 交易统计类及相关操作
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "trade_conclude.h"

trade_conclude trade_conclude_create()
{
    trade_conclude tc;
    memset(&tc, 0, sizeof(trade_conclude));
    return tc;
}

void show_trade_conclude(trade_conclude* tc)
{
    printf("招待客户总数：%d\n", tc->customers_num);
    printf("总流水：%.2lf\n", tc->flowing_water);
    printf("总存款量：%.2lf\n", tc->total_deposits);
    printf("逗留总时间：");
    show_time(tc->total_time);
    printf("逗留平均时间：");
    if (tc->customers_num != 0)
        show_time(tc->total_time/tc->customers_num);
    else
        show_time(0);
}

void show_time(int seconds)
{
    int all_hours = seconds / 3600;
    int all_minutes = (seconds % 3600) / 60;
    int all_seconds = seconds % 60;
    printf("%d 小时 %d 分钟 %d 秒\n", all_hours, all_minutes, all_seconds);
}