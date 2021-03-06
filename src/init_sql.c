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
    if (!(mysql_real_connect(&mysql_connect, mysql_host,
                             mysql_user, mysql_pwd, mysql_db,
                             mysql_connect_port, NULL, 0)))
    {
        printf("Failed to access to the database...Error: %s\n",
               mysql_error(&mysql_connect));
    }
    if (!mysql_set_character_set(&mysql_connect, "gbk"))
    {
        printf("New client character set: %s\n",
               mysql_character_set_name(&mysql_connect));
    }
}
