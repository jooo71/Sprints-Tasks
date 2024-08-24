/*
 * sort.h
 *
 *  Created on: Aug 8, 2023
 *      Author: PC
 */

#ifndef SORT_H_
#define SORT_H_

#define Array_Size 12

typedef unsigned char uint8_t;
typedef char int8_t;
typedef int int32_t;
int8_t insertionSort(int32_t *array, uint8_t arraySize);
void printArray(int32_t *array, uint8_t arraySize);

#endif /* SORT_H_ */
