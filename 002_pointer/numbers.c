
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "numbers.h"

int getNumbers(int *nums,int size)
{
    printf("input numbers\n");
    for(uint8_t i=0; i<size; i++)
    {
        printf("[%d] -> ",i+1);
        scanf("%d",&nums[i]);
        printf("\n");
    }

    return 1;
}

void printNumbers(int *nums, int size)
{
    printf("\n\nnumbers\n\n");
    for(uint8_t i=0; i<size; i++)
    {
        printf("num %d -> %d",i+1,*(nums+i));
        printf("\t");
    }
}