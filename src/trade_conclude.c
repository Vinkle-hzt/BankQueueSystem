#include "trade_conclude.h"

trade_conclude trade_conclude_create()
{
    trade_conclude tc;
    memset(&tc, 0, sizeof(trade_conclude));
    return tc;
}