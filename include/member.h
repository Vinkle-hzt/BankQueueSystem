/**
 * @file member.h
 * @brief 客户类及相关操作
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#define NAME_SIZE 20 ///< 客户姓名长度

#include "helpful_func.h"
#include "common.h"
#include "date.h"
#include "string.h"

/**
 * @brief 客户
 * 
 */
typedef struct
{
    int ID;                    ///< 客户 ID
    int common_pick_num;       ///< 普通号码
    int vip_pick_num;          ///< 客户取的号码
    int vip;                   ///< vip 等级
    char name[NAME_SIZE];      ///< 客户姓名
    int come_time;             ///< 客户到达时间
    int leave_time;            ///< 客户离开时间
} member;

/**
 * @brief 客户进入银行取号
 * 
 * @param ID 客户 ID
 * @param name 客户姓名
 * @return member* 客户指针
 */
member *member_come(int ID, char *name);



/**
 * @brief 客户比较函数
 * 
 * @param lhs 客户指针1
 * @param rhs 客户指针2
 * @return int 比较结果
 */
int member_compare(const void* lhs, const void* rhs);

/**
 * @brief 获取vip等级
 * 
 * @param ID 客户 ID
 * @param name 客户姓名
 * @return int 客户vip等级
 */
int get_vip_level(int* ID, char *name);

/**
 * @brief 更新取号号码
 * 
 * @param m 客户指针
 */
void update_pick(member* m);
