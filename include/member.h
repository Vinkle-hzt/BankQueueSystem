#pragma once

#define NAME_SIZE 20

#include "safe_free.h"
#include "common.h"
#include "date.h"
#include "string.h"

typedef struct
{
    int ID;
    int pick_num;
    char name[NAME_SIZE];
} member;

member* member_come(int ID, char* name);

void member_leave(member* m);