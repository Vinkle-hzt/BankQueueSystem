#pragma once

#include <stdlib.h>
#include "safe_free.h"
/**
 * @brief queue node type
 * 
 */
typedef struct node
{
    void *data;        ///< data
    struct node *pre;  ///< pre node
    struct node *next; ///< next node
} queue_node;

/**
 * @brief 
 * 
 * @param val 
 * @param pre 
 * @param next 
 * @return queue_node* 
 */
queue_node *queue_node_create(void *val, queue_node *pre, queue_node *next);

/**
 * @brief 
 * 
 * @param qn 
 */
void queue_node_free(queue_node *qn);