/**
 * @file common.h
 * @brief 存储全局变量
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#define VIP_LEVEL 3

#include <stdio.h>
#include "trade_conclude.h"
#include "array_list.h"
#include "queue.h"

extern int cur_common_num;             ///< 总叫号
extern int cur_pick_num[VIP_LEVEL];    ///< 当前取号号码
extern int cur_call_num[VIP_LEVEL];    ///< 当前叫号号码
extern FILE *log_file;                 ///< log输出文件
extern queue *waiting_line;            ///< 等待队列
extern array_list *counters;           ///< 柜台数组
extern trade_conclude all_trade;       ///< 交易总量
extern const char *admin_account_file; ///< 管理员用户账号文件
extern const char *user_account_file;  ///< 普通用户账号文件
extern const char *vip_level_file;     ///< vip等级文件