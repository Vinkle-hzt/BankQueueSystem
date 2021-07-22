#pragma once

#define NAME_SIZE 20

#include "safe_free.h"
#include "common.h"
#include "date.h"
#include "string.h"

/**
 * @brief 客户
 * 
 */
typedef struct
{
    int ID;               ///< 客户 ID
    int pick_num;         ///< 客户取的号码
    char name[NAME_SIZE]; ///< 客户姓名
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
 * @brief 客户离开银行
 * 
 * @param m 客户指针
 */
void member_leave(member *m);