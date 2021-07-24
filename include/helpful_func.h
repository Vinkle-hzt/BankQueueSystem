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
 * @brief 释放指针P并将p设为NULL
 * 
 * @param p 需要释放的指针
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
 * @brief 在文件 f 中输出 md5 编码
 * 
 * @param f 输出文件
 * @param md5 输出 md5 编码
 */
void printMD5(FILE* f, uint8_t* md5);

/**
 * @brief 交换函数
 * 
 * @param lhs 变量指针 1
 * @param rhs 变量指针 2
 * @param size 交换变量大小
 */
void swap(void *lhs, void *rhs, int size);

