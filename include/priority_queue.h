/**
 * @file priority_queue.h
 * @brief 优先队列类
 * 
 * @copyright Copyright (c) 2021
 * 
 */

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
 * @brief 创建一个优先队列
 * 
 * @param CompFunc 比较函数
 * @return priority_queue* 优先队列指针
 */
priority_queue *pq_create(int (*CompFunc)(const void *, const void *));

/**
 * @brief 当数组容量不足时扩充
 * 
 * @param pq 优先队列指针
 */
void pq_resize(priority_queue *pq);

/**
 * @brief 维护堆的性质
 * 
 * @param pq 优先队列指针
 * @param i 元素位置
 */
void pq_heapify(priority_queue *pq, int i);

/**
 * @brief 将元素插入优先队列
 * 
 * @param pq 优先队列指针
 * @param elem 元素指针
 */
void pq_push(priority_queue *pq, void *elem);

/**
 * @brief 将元素从优先队列中弹出
 * 
 * @param pq 优先队列指针
 */
void pq_pop(priority_queue *pq);

/**
 * @brief 获取在优先队列头元素的指针
 * 
 * @param pq 优先队列指针
 * @return void* 元素指针
 */
void *pq_top(priority_queue *pq);

/**
 * @brief 释放优先队列空间
 * 
 * @param pq 优先队列指针
 */
void pq_free(priority_queue *pq);

/**
 * @brief 清空优先队列
 * 
 * @param pq 优先队列指针
 */
void pq_clear(priority_queue *pq);
