/**
 * @file common.c
 * @brief 存储全局变量
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "common.h"

int cur_common_num = 0;              ///< 总叫号
int cur_pick_num[VIP_LEVEL] = {0};   ///< 当前取号号码
int cur_call_num[VIP_LEVEL] = {0};   ///< 当前叫号号码
FILE *log_file = NULL;               ///< log输出文件
priority_queue *waiting_line = NULL; ///< 等待队列
array_list *counters = NULL;         ///< 柜台数组
trade_conclude all_trade;            ///< 交易总量
MYSQL mysql_connect;                 ///<数据源指针
MYSQL_RES *mysql_res;                ///<查询结果集
MYSQL_FIELD *mysql_field;            ///<包含字段信息的结构指针
MYSQL_ROW mysql_next_row;            ///<存放查询sql语句字符串数组
char mysql_buffer[2048];             ///< sql buffer
int member_error_1 = -1;                  ///< 姓名不匹配错误
int member_error_2 = -2;                  ///< 没有ID号码错误
