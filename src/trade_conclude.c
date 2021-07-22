/**
 * @file trade_conclude.h
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
    printf("总流水：%d\n", tc->flowing_water);
    printf("总存款量：%d\n", tc->total_deposits);
    printf("总贷款量：%d\n", tc->total_loans);
}