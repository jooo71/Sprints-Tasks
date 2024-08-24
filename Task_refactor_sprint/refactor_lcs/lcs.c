/*
 * lcs.c
 *
 *  Created on: Aug 8, 2023
 *      Author: PC
 */
#include "lcs.h"

int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS)
{
	insertionSort(array,arraySize);
	uint8_t iterator=1;
	uint8_t max=0;
	if (arraySize==0 || arraySize >10)
	{
		return -2;
	}
	for (uint8_t i = 0; i < arraySize-1; i++)
	{
		if (array[i+1]-array[i]==1)
		{
			iterator++;
			if (iterator>max)
			{
				max=iterator;
			}
		}
		else
		{
			iterator=1;
		}
	}
	*sizeofLCS=max;
	if (max==0)
	{
		return -3;
	}
	return 0;

}
