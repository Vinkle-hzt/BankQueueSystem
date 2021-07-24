/**
 * @file display.c
 * @brief 功能面板的展示
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "display.h"

void show_welcome_message()
{
    printf("\n ------------------------------------------------\n");
    printf("|    *  **       *    *                *  *      |\n");
    printf("|     **  **    *   **              *  ****  *   |\n");
    printf("|          **   ** **   *          *  ******  *  |\n");
    printf("|     **   **   *   ****            *  ****  *   |\n");
    printf("|      *** **  *****                   *  *      |\n");
    printf("|         *** **                                 |\n");
    printf("|          ***                                   |\n");
    printf("|          ***          欢迎光临银行!            |\n");
    printf("|          ***                                   |\n");
    printf("|          ***                                   |\n");
    printf("|          ***                                   |\n");
    printf("|         ****                                   |\n");

}

void show_main_menu()
{
    printf(" ------------------------------------------------\n");
    printf("|                                                |\n");
    printf("|              1.取号                            |\n");
    printf("|              2.办理业务                        |\n");
    printf("|              3.查看交易量                      |\n");
    printf("|              0.结束交易                        |\n");
    printf("|                                                |\n");
    printf(" ------------------------------------------------\n");
}

void show_basicbusiness_menu()
{
    printf(" ------------------------------------------------\n");
    printf("|                                                |\n");
    printf("|            1.查询余额                          |\n");
    printf("|            2.存款                              |\n");
    printf("|            3.取款                              |\n");
    printf("|            4.转账                              |\n");
    printf("|            5.查看交易记录                      |\n");
    printf("|            0.结束业务办理                      |\n");
    printf("|                                                |\n");
    printf(" ------------------------------------------------\n");
}

void show_exit_message()
{
    printf("              ******           ******            \n");
    printf("           ***********       ***********         \n");
    printf("          **************   **************        \n");
    printf("         *********************************       \n");
    printf("         ***********------------**********       \n");
    printf("          **********|  Goodbye | *********       \n");
    printf("           *********------------********         \n");
    printf("             *************************           \n");
    printf("               *********************             \n");
    printf("                 ******************              \n");
    printf("                   **************                \n");
    printf("                     **********                  \n");
    printf("                       ******                    \n");
}