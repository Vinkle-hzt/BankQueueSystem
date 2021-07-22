/**
 * @file common.c
 * @brief 存储全局变量
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "common.h"

int cur_pick_num = 0;

int cur_call_num = 0;

FILE* log_file = NULL;

queue *waiting_line = NULL;

array_list *counters = NULL;
