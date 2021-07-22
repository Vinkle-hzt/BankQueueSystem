#pragma once

#include <stdlib.h>
#include "array_list.h"
#include "display.h"
#include "queue.h"
#include "member.h"
#include "safe_free.h"
#include "date.h"
#include "common.h"
#include "trade_conclude.h"
#include "counter.h"

typedef struct
{
    date trade_time;
    Trade_type trade_type;
} trade_info;

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