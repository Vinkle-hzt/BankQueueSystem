/**
 * @file common.h
 * @brief 存储全局变量
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#define VIP_LEVEL 3   ///< VIP 等级
#define COUNTER_NUM 3 ///< 柜台个数

#include <stdio.h>
#include <mysql.h>
#include "trade_conclude.h"
#include "array_list.h"
#include "priority_queue.h"

extern int cur_common_num;           ///< 总叫号
extern int cur_pick_num[VIP_LEVEL];  ///< 当前取号号码
extern int cur_call_num[VIP_LEVEL];  ///< 当前叫号号码
extern FILE *log_file;               ///< log输出文件
extern priority_queue *waiting_line; ///< 等待队列
extern array_list *counters;         ///< 柜台数组
extern trade_conclude all_trade;     ///< 交易总量
extern MYSQL mysql_connect;          ///<数据源指针
extern MYSQL_RES *mysql_res;         ///<查询结果集
extern MYSQL_FIELD *mysql_field;     ///<包含字段信息的结构指针
extern MYSQL_ROW mysql_next_row;     ///<存放查询sql语句字符串数组
extern char mysql_buffer[2048];      ///< sql buffer
extern int member_error_1;           ///< 姓名不匹配错误
extern int member_error_2;           ///< 没有ID号码错误
extern const char *mysql_host;       ///< mysql host 地址
extern const char *mysql_user;       ///< mysql 用户名
extern const char *mysql_pwd;        ///< mysql 密码
extern const char *mysql_db;         ///< mysql 数据库名称
extern int mysql_connect_port;       ///< mysql 数据库端口号