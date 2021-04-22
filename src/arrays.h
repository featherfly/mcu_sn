#ifndef ARRAYS_H
#define ARRAYS_H

#ifndef byte
typedef unsigned char byte;
#endif

bool array_equals(const byte source[], const char target[], unsigned int len);

bool array_equals(const char source[], const char target[], unsigned int len);

/**
 * @param source 复制源 
 * @param target 复制目标
 * @param size 复制数量
 */
int array_copy(const byte source[], byte target[], unsigned int size);

int array_copy(const char source[], char target[], unsigned int size);

/**
 * @param source 复制源 
 * @param target 复制目标
 * @param start 复制源开始索引（包含）
 * @param size 复制数量
 */
int array_copy(const byte source[], byte target[], unsigned int start, unsigned int size);

/**
 * @param target 设置目标
 * @param source 设置源 
 * @param start 目标起始位置
 * @param len 源数组长度
 */
int array_set(char target[], const char source[], unsigned int start, unsigned int len);

#endif