#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



int main(void)
{
    int8_t size,min_val,max_val;
    printf("array size:\t");
    scanf("%hhd", &size);
    int8_t *arr = (int8_t*)malloc(sizeof(int8_t)*size);

    for(int8_t i=0; i<size; i++)
    {
        printf("[%d]:\t",i);
        scanf("%hhd", arr + i);
    }

    min_val = max_val = *arr;

    for(int8_t i=1; i<size; i++)
    {
        if(*(arr+i) < min_val)
        {
            min_val = *(arr+i);
        }

        if(*(arr+i) > max_val)
        {
            max_val = *(arr+i);
        }
    }


    printf("min_val=%d\n",min_val);
    printf("max_val=%d\n",max_val);

    free(arr);


    return 0;
}