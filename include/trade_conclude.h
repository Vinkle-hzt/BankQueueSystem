/**
 * @file trade_conclude.h
 * @brief 交易统计类及相关操作
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <string.h>
#include <stdio.h>
/**
 * @brief 交易统计类型
 * 
 */
typedef struct
{
    int customers_num;     ///< 接待客户总数
    double flowing_water;  ///< 总流水
    double total_deposits; ///< 总存款量
    int total_time;        ///< 用户逗留时间
} trade_conclude;

/**
 * @brief 建立交易统计对象
 * 
 * @return trade_conclude 交易统计
 */
trade_conclude trade_conclude_create();

/**
 * @brief 展示交易统计
 * 
 * @param tc 交易统计类指针
 */
void show_trade_conclude(trade_conclude *tc);

/**
 * @brief 根据时间戳展示时间
 * 
 * @param seconds 时间戳
 */
void show_time(int seconds);