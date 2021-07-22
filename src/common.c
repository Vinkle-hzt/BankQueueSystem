/**
 * @file common.c
 * @brief 存储全局变量
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "common.h"

int cur_common_num = 0;                                ///< 总叫号
int cur_pick_num[VIP_LEVEL] = {0};                     ///< 当前取号号码
int cur_call_num[VIP_LEVEL] = {0};                     ///< 当前叫号号码
FILE *log_file = NULL;                                 ///< log输出文件
priority_queue *waiting_line = NULL;                   ///< 等待队列
array_list *counters = NULL;                           ///< 柜台数组
trade_conclude all_trade;                              ///< 交易总量
const char *admin_account_file = "../files/admin.txt"; ///< 管理员用户账号文件
const char *user_account_file = "../files/user.txt";   ///< 普通用户账号文件
const char *vip_level_file = "../files/vip.txt";       ///< vip等级文件