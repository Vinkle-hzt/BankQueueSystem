/**
 * @file init_sql.c
 * @brief 初始化 mysql 连接
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "init_sql.h"

void start_mysql()
{
    printf("start mysql...\n");
    mysql_init(&mysql_connect);
    if (!(mysql_real_connect(&mysql_connect, "localhost", "root", "15868372516", "bank_queue_system", 3306, NULL, 0)))
    {
        printf("Failed to access to the database...Error: %s\n", mysql_error(&mysql_connect));
    }
    if (!mysql_set_character_set(&mysql_connect, "gbk"))
    {
        printf("New client character set: %s\n",
               mysql_character_set_name(&mysql_connect));
    }
}