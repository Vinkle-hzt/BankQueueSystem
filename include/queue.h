#pragma once

#include <stdlib.h>
#include "queue_node.h"
#include "safe_free.h"

/**
 * @brief 队列类
 * 
 */
typedef struct
{
    queue_node *head; ///< 队列头（留空）
    int size;         ///< 队列元素个数
} queue;

/**
 * @brief 创建一个队列
 * 
 * @return queue* 队列指针
 */
queue *queue_create();

/**
 * @brief 将元素放入队列中
 * 
 * @param q 队列指针
 * @param val 元素指针
 */
void queue_push(queue *q, void *val);

/**
 * @brief 将元素从队列中取出
 * 
 * @param q 队列指针
 * @return void* 元素指针
 */
void *queue_pop(queue *q);

/**
 * @brief 释放队列空间
 * 
 * @param q 队列指针
 */
void queue_free(queue *q);