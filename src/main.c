/**
 * @file main.c
 * @brief 系统主入口函数
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include "bank_queue_system.h"

int main()
{
    printMD5(stdout, getMD5("admin"));
    printf("\n");
    start_system();
    return 0;
}
