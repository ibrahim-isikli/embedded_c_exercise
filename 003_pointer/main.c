#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "random_num.h"


int main(void)
{
    int arrSize;
    int min,max;

    printf("input array size: ");
    scanf("%d",&arrSize);

    // allocate memory
    int *randomNums =(int*)malloc(arrSize*sizeof(int));

    if(randomNums == NULL)
    {
        printf("memory allacation failed!\n");
        return 1;
    }

    paddingRandoms(randomNums,arrSize);
    findMinMax(randomNums,arrSize,&min,&max);

    printf("min value: %d\n",min);
    printf("max value: %d\n",max);

    free(randomNums);
}
