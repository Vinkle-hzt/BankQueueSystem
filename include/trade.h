#pragma once

#include "display.h"
#include "common.h"
#include "counter.h"

enum Trade_type
{
    Deposit,
    Withdraw,
    Transfer,
    BeTransferred
};

typedef struct
{
    int user_ID;
    int card_ID;
    double money;
} card;

/**
 * @brief 交易主函数入口
 * 
 */
void start_trade();

int show_cards(int ID);

card choose_card(int ID);

void check_balance(int card_ID);

void deposit_money(counter *ct, int card_ID);

void withdraw_money(counter *ct, int card_ID);

void transfer_accounts(counter *ct, int card_ID);

void view_transactions(int card_ID);

/**
 * @brief 结束当前柜台业务
 * 
 * @param ct 柜台指针
 */
void end_trade(counter *ct);

/**
 * @brief 为客户办理银行卡
 * 
 * @param ID 客户号
 */
void create_card(int ID);

/**
 * @brief 检查银行卡号和客户是否匹配
 * 
 * @param card_ID 银行卡号
 * @param user_ID 客户号
 * @return int 0 不匹配 1 匹配
 */
int check_card(int card_ID, int user_ID);

/**
 * @brief 叫下一个客户
 * 
 * @param ct 柜台指针
 */
void call_next(counter *ct);

double get_balance(int card_ID);

void upload_trade(int card_ID, enum Trade_type ty,
               double pre_money, double cur_money, int trade_ID);
