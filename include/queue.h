#pragma once

#include <stdlib.h>
#include "queue_node.h"
#include "safe_free.h"

typedef struct
{
    queue_node* head;
    int size;
} queue;

/**
 * @brief 
 * 
 * @return queue* 
 */
queue* queue_create();

/**
 * @brief 
 * 
 * @param q 
 * @param val 
 */
void queue_push(queue*q, void* val);

/**
 * @brief 
 * 
 * @param q 
 * @return void* 
 */
void* queue_pop(queue*q);

/**
 * @brief 
 * 
 * @param q 
 */
void queue_free(queue*q);