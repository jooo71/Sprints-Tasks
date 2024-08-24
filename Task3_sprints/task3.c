#include <stdio.h>
#include <stdlib.h>
// #include <ctype.h>
// #include <time.h>
/*
 *
 *  Created on: Mar 27, 2023
 *      Author: youseif essam
 */
#define Array_Size 12

typedef unsigned char uint8_t;
typedef char int8_t;
typedef int int32_t;
int8_t insertionSort(int32_t *array, uint8_t arraySize);
void printArray(int32_t *array, uint8_t arraySize);
int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS);
uint8_t size=0;
uint8_t iterator1=1;
uint8_t sizeee=0;

int main(int argc, char const *argv[])
{
	printf("enter size");
	scanf("%d",&sizeee);
	printf("enter your elemnts");
	int32_t *arr = (int32_t*) malloc(sizeee * sizeof(int32_t));
	for (uint8_t i = 0; i < sizeee; i++)
	{
		scanf("%d",&arr[i]);
	}
	
    // insertionSort(arr,sizeee);
	lcsGetSize(arr,sizeee,&size);
	// printArray(arr,sizeee);
	printf("the size:%d",size);
    


    return 0;
}

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
	

