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
    
    // 如果不存在表，就新建数据表
    mysql_query(&mysql_connect, "SET NAMES utf8mb4;");
    mysql_query(&mysql_connect, "SET FOREIGN_KEY_CHECKS = 0;");
    mysql_query(&mysql_connect,
                "CREATE TABLE IF NOT EXISTS `admin`  ("
                "`ID` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,"
                "`password` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,"
                "PRIMARY KEY (`ID`) USING BTREE"
                ") ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;");
    mysql_query(&mysql_connect,
                "CREATE TABLE IF NOT EXISTS `card`  ("
                "`card_ID` int NOT NULL AUTO_INCREMENT,"
                "`user_ID` int NULL DEFAULT NULL,"
                "`money` double NULL DEFAULT NULL,"
                "PRIMARY KEY (`card_ID`) USING BTREE"
                ") ENGINE = InnoDB AUTO_INCREMENT = 10004 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;");
    mysql_query(&mysql_connect,
                "CREATE TABLE IF NOT EXISTS `trade`  ("
                "`trade_num` int NOT NULL AUTO_INCREMENT,"
                "`card_ID` int NULL DEFAULT NULL,"
                "`trade_type` int NULL DEFAULT NULL,"
                "`trade_time` datetime NULL DEFAULT NULL,"
                "`pre_money` double NULL DEFAULT NULL,"
                "`cur_money` double NULL DEFAULT NULL,"
                "`trade_ID` int NULL DEFAULT NULL,"
                "PRIMARY KEY (`trade_num`) USING BTREE"
                ") ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = DYNAMIC;");
    mysql_query(&mysql_connect,
                "CREATE TABLE IF NOT EXISTS `user`  ("
                "`user_ID` int NOT NULL AUTO_INCREMENT,"
                "`name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,"
                "`vip` int NULL DEFAULT NULL,"
                "PRIMARY KEY (`user_ID`) USING BTREE"
                ") ENGINE = InnoDB AUTO_INCREMENT = 10012 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;");
    mysql_query(&mysql_connect, "SET FOREIGN_KEY_CHECKS = 1;");
}
