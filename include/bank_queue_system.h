/**
 * @file bank_queue_system.h
 * @brief 银行排队系统相关函数
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once

#include <stdlib.h>
#include "array_list.h"
#include "display.h"
#include "queue.h"
#include "member.h"
#include "helpful_func.h"
#include "date.h"
#include "common.h"
#include "trade_conclude.h"
#include "counter.h"

/**
 * @brief 启动银行排队系统
 * 
 */
void start_system();

/**
 * @brief 进行叫号
 * 
 */
void do_pick_number();

/**
 * @brief 
 * 
 * @return int 0 登录失败
 *             1 登录成功
 */
int login_admin();