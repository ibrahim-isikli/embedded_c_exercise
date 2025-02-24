#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



int main(void)
{
    int8_t size,min_val,max_val;
    printf("array size:\t");
    scanf("%d",&size);
    int8_t *arr = (int8_t*)malloc(sizeof(uint8_t)*size);

    for(int8_t i=0; i<size; i++)
    {
        printf("[%d]:\t",i);
        scanf("%d",arr+i);
    }


    *arr = min_val = max_val;

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


    printf("min_val=%d",min_val);
    printf("max_val=%d",max_val);

    


    return 0;
}