/**
 * @file helpful_func.h
 * @brief 存储一些实用函数
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/**
 * @brief free pointer p and set p to NULL
 * 
 * @param p free pointer
 */
void safe_free(void* p);

/**
 * @brief 获取字符的 MD5 编码
 * 
 * @param msg 字符串
 * @return uint8_t* MD5 编码指针
 */
uint8_t* getMD5(char* msg);

/**
 * @brief 
 * 
 * @param f 
 * @param md5 
 */
void printMD5(FILE* f, uint8_t* md5);