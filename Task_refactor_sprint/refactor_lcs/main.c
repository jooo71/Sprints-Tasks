/*
 * main.c
 *
 *  Created on: Aug 8, 2023
 *      Author: PC
 */
#include "main.h"
uint8_t size=0;
uint8_t iterator1=1;
uint8_t sizeee=0;
uint8_t joo=0;
int main(int argc, char const *argv[])
{
	printf("enter size");
	fflush(stdout);
	scanf("%d",&sizeee);
	printf("enter your elemnts");
	fflush(stdout);
	int32_t *arr = (int32_t*) malloc(sizeee * sizeof(int32_t));

	for (uint8_t i = 0; i < sizeee; i++)
	{
		scanf("%d",&arr[i]);
	}

//     insertionSort(arr,sizeee);
	lcsGetSize(arr,sizeee,&size);
//	 printArray(arr,sizeee);
	printf("the size:%d",size);



    return 0;
}
