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
}