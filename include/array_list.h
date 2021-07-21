#pragma once
#define AL_DEFAULT_SIZE 100

/**
 * @brief  a list implement by array, the list 
 *         will append its size automatically
 * 
 */
typedef struct
{
    void **data;                                 ///< element data
    int curSize;                                 ///< element array current size
    int maxSize;                                 ///< element array max size
} array_list;

/**
 * @brief create array list
 * 
 * @param CompFunc compare function
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