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

void show_cards();

// card choose_card(int ID);

// void check_balance(card*);

// void deposit_money(card*);

// void withdraw_money(card*);

// void transfer_accounts(card*);

// void view_transactions(card*);
