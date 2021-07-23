#pragma once

#include "display.h"
#include "common.h"
#include "counter.h"

typedef struct
{
    int user_ID;
    int card_ID;
    double money;
} card;

void start_trade();

int show_cards(int ID);

card choose_card(int ID);

void check_balance(int card_ID);

void deposit_money(int card_ID);

void withdraw_money(int card_ID);

void transfer_accounts(int card_ID);

void view_transactions(int card_ID);

void end_trade(counter* ct);

void create_card(int ID);

int check_card(int card_ID, int user_ID);