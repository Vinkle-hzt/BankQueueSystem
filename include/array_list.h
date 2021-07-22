#pragma once
#define AL_DEFAULT_SIZE 10

#include "safe_free.h"
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
 * @brief create array list
 * 
 * @return array_list* array_list pointer
 */
array_list *al_create();

/**
 * @brief get the idx_th element value (start from 0)
 * 
 * @param al array list
 * @param idx index
 * @return void* element pointer
 */
void *al_at(array_list *al, int idx);

/**
 * @brief insert element value val to the end of array list
 * 
 * @param al array list
 * @param val element value
 */
void al_push(array_list *al, void *val);

/**
 * @brief free the array list
 * 
 * @param al array list
 */
void al_free(array_list *al);

/**
 * @brief resize the array list size
 * 
 * @param al array list
 */
void al_resize(array_list *al);

/**
 * @brief delete the last value of array list
 * 
 * @param al array list
 * @param idx index
 * @return void* 
 */
void *al_pop(array_list *al, int idx);

/**
 * @brief clean the array list
 * 
 * @param al array list
 */
void al_clean(array_list *al);