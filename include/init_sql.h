/**
 * @file init_sql.h
 * @brief 初始化 mysql 连接
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#include <mysql.h>
#include "common.h"

/**
 * @brief 启动 mysql 服务器
 * 
 */
void start_mysql();