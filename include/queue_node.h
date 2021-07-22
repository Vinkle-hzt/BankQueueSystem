/**
 * @file queue_node.h
 * @brief 队列节点类及相关操作
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <stdlib.h>
#include "helpful_func.h"

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
 * @brief 创建一个 queue node
 * 
 * @param val 节点值指针
 * @param pre 节点前驱指针
 * @param next 节点后驱指针
 * @return queue_node* 队列节点指针
 */
queue_node *queue_node_create(void *val, queue_node *pre, queue_node *next);

/**
 * @brief 释放队列节点空间
 * 
 * @param qn 队列节点指针
 */
void queue_node_free(queue_node *qn);