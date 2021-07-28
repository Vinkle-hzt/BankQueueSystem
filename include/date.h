/**
 * @file date.h
 * @brief 日期类及相关操作
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#include <time.h>
#include <stdio.h>

/**
 * @brief 日期类
 * 
 */
typedef struct
{
    int year;   ///< 年
    int month;  ///< 月
    int day;    ///< 日
    int hour;   ///< 时
    int minute; ///< 分
} date;

/**
 * @brief 获取当前时间
 * 
 * @return date 日期类
 */
date get_cur_date();

/**
 * @brief 在文件 f 中显示日期 d
 * 
 * @param f 输出文件
 * @param d 输出日期
 */
void show_date(FILE *f, date d);

/**
 * @brief 获取当前时间戳
 * 
 * @return int 时间戳
 */
int get_cur_seconds();