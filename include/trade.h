/**
 * @file trade.h
 * @brief 实现交易业务
 * @date 2021-07-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once

#include "display.h"
#include "common.h"
#include "counter.h"

/**
 * @brief 交易类型
 * 
 */
enum Trade_type
{
    Deposit,      ///<存款
    Withdraw,     ///<取款
    Transfer,     ///<转账
    BeTransferred ///< 被转账
};

/**
 * @brief 交易主函数入口
 * 
 */
void start_trade();

/**
 * @brief 展示客户卡的信息
 * 
 * @param ID 
 * @return int 卡的数量
 */
int show_cards(int ID);

/**
 * @brief 查询卡内余额
 * 
 * @param card_ID 银行卡号
 */
void check_balance(int card_ID);

/**
 * @brief 存钱业务
 * 
 * @param ct 柜台号码
 * @param card_ID 银行卡号
 */
void deposit_money(counter *ct, int card_ID);

/**
 * @brief 取钱业务
 * 
 * @param ct 柜台指针
 * @param card_ID 银行卡号
 */
void withdraw_money(counter *ct, int card_ID);

/**
 * @brief 转账业务
 * 
 * @param ct 柜台指针
 * @param card_ID 银行卡号
 */
void transfer_accounts(counter *ct, int card_ID);

/**
 * @brief 查看交易记录
 * 
 * @param card_ID 银行卡号
 */
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

/**
 * @brief 返回银行卡余额
 * 
 * @param card_ID 银行卡号
 * @return double 卡内余额
 */
double get_balance(int card_ID);

/**
 * @brief 获取交易记录
 * 
 * @param card_ID 银行卡号
 * @param ty 交易类型
 * @param pre_money 交易前金额
 * @param cur_money 交易后金额
 * @param trade_ID 交易对象卡号
 */
void upload_trade(int card_ID, enum Trade_type ty,
                  double pre_money, double cur_money, int trade_ID);
