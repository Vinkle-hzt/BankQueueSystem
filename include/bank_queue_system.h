#pragma once

#include <stdlib.h>
#include "array_list.h"
#include "display.h"
#include "queue.h"
#include "member.h"
#include "safe_free.h"
#include "pick_number.h"
#include "date.h"
#include "common.h"

typedef struct
{
    date trade_time;
    Trade_type trade_type;
} trade_info;

void start_system();
