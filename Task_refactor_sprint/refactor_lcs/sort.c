/*
 * sort.c
 *
 *  Created on: Aug 8, 2023
 *      Author: PC
 */

#include "sort.h"
int8_t insertionSort(int32_t *array, uint8_t arraySize)
{
    int8_t temp;
    int8_t prevouis;
	uint8_t iterator=0;
	if (arraySize==0 || arraySize >10)
	{
		return -2;
	}

	for (uint8_t i = 1; i < arraySize; i++) {
		temp = array[i];
		prevouis = i - 1;

		while (prevouis >= 0 && array[prevouis] > temp) {
			array[prevouis + 1] = array[prevouis];
			prevouis = prevouis - 1;
		}
		array[prevouis + 1] = temp;

	}
	return 0;


}

void printArray(int32_t *array, uint8_t arraySize)
{
	for (uint8_t i = 0; i < arraySize; i++)
    {
        printf("%d\n",array[i]);
    }
}
