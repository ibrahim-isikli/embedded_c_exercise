#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "random_num.h"

void paddingRandoms(int *arr, int size)
{
    srand(time(0));
    fiilArr(arr,size);
    printArr(arr,size);
}

void fiilArr(int *arr, int size)
{
    for(uint8_t i=0; i<size; i++)
    {
        *(arr+i) = rand() % 101;
    }
}

void printArr(int *arr, int size)
{
    printf("\narray result\n");
    for(uint8_t i=0; i<size; i++)
    {
        printf("[%d] -> %d\n",i+1,*(arr+i));
    }

}


void findMinMax(int *arr, int size, int *min, int *max)
{
    *min = *max = *arr;
    for(int i=1; i<size; i++)
    {
        if(*(arr+i) < *(min))
        {
            *min = *(arr+i);
        }

        if(*(arr+i) > *(max))
        {
            *max = *(arr+i);
        }
        
    }
}