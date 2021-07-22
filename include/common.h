#pragma once

#include <stdio.h>
#include "array_list.h"
#include "queue.h"

extern int cur_pick_num;     ///< 当前取号号码
extern int cur_call_num;     ///< 当前叫号号码
extern FILE *log_file;       ///< log输出文件
extern queue *waiting_line;  ///< 等待队列
extern array_list *counters; ///< 柜台数组
