#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "numbers.h"



int main(void)
{
    int  arraySize;
    printf("array size:\t");
    scanf("%d",&arraySize);

    // allocate dynamic memory
    int *nums =(uint8_t*)malloc(arraySize*sizeof(uint8_t));
    if(nums == NULL)
    {
        printf("memory allocation failed !\n");
        return 1;
    }

    getNumbers(nums,arraySize);
    printNumbers(nums,arraySize);
    
}
