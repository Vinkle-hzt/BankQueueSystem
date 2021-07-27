/**
 * @file array_list.h
 * @brief array_list 类及相关操作
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#define AL_DEFAULT_SIZE 10 ///< 可增长数组初始容量

#include "helpful_func.h"
#include <string.h>

/**
 * @brief  用数组实现的线性表，该线性表会自动扩充容量
 * 
 */
typedef struct
{
    void **data; ///< 数据数组
    int curSize; ///< 数组当前大小
    int maxSize; ///< 数据最大大小
} array_list;

/**
 * @brief 创建一个线性表
 * 
 * @return array_list* 线性表指针
 */
array_list *al_create();

/**
 * @brief 获得线性表中相应位置元素的指针（从0开始）
 * 
 * @param al 线性表指针
 * @param idx 元素位置
 * @return void* 元素指针
 */
void *al_at(array_list *al, int idx);

/**
 * @brief 将元素插入线性表末尾
 * 
 * @param al 线性表指针
 * @param val 元素指针
 */
void al_push(array_list *al, void *val);

/**
 * @brief  释放线性表分配空间
 * @param al 线性表指针
 */
void al_free(array_list *al);

/**
 * @brief 自动增长线性表
 * 
 * @param al 线性表指针
 */
void al_resize(array_list *al);

/**
 * @brief 删除线性表相应位置元素（从0开始）
 * 
 * @param al 线性表指针
 * @param idx 相应位置
 * @return void* 元素指针
 */
void *al_pop(array_list *al, int idx);

/**
 * @brief 将线性表清空
 * 
 * @param al 线性表指针
 */
void al_clean(array_list *al);