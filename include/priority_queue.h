#pragma once
#define PQ_DEFAULT_SIZE 10

#include <stdlib.h>
#include <string.h>
#include "helpful_func.h"

/**
 * @brief 优先队列类，能够自动扩充容量
 * 
 */
typedef struct
{
    int maxSize;                     ///< 最大容量
    int curSize;                     ///< 当前容量
    void **data;                     ///< 数据数组
    int (*CompFunc)(const void *, const void *); ///< 比较函数
} priority_queue;

/**
 * @brief 
 * 
 * @param CompFunc 
 * @return priority_queue* 
 */
priority_queue *pq_create(int (*CompFunc)(const void *, const void *));

/**
 * @brief 
 * 
 * @param pq 
 */
void pq_resize(priority_queue *pq);

/**
 * @brief 
 * 
 * @param pq 
 * @param i 
 */
void pq_heapify(priority_queue *pq, int i);

/**
 * @brief 
 * 
 * @param pq 
 * @param elem 
 */
void pq_push(priority_queue *pq, void *elem);

/**
 * @brief 
 * 
 * @param pq 
 */
void pq_pop(priority_queue *pq);

/**
 * @brief 
 * 
 * @param pq 
 * @return void* 
 */
void *pq_top(priority_queue *pq);

/**
 * @brief 
 * 
 * @param pq 
 */
void pq_free(priority_queue *pq);

/**
 * @brief 
 * 
 * @param pq 
 */
void pq_clear(priority_queue *pq);
