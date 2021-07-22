#pragma once

#include "member.h"
#include "trade_conclude.h"

/**
 * @brief 柜台类，用于存储柜台信息
 * 
 */
typedef struct
{
    int number;         ///<柜台号
    trade_conclude kpi; ///< 柜台 kpi
    member *customer;   ///< 柜台当前用户
} counter;

/**
 * @brief 创建一个 array_list* 类型的柜台表
 * 
 * @param num 柜台个数
 * @return array_list* 柜台的线性表
 */
array_list *create_counter(int num);

/**
 * @brief 将客户分配到柜台
 * 
 * @param ct 柜台指针
 * @param customer 客户指针
 */
void counter_assign_customer(counter *ct, member *customer);