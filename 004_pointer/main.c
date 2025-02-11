#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int matrix[3][3] = 
{
    {1,2,3},
    {4,5,6},
    {7,8,9}
};


int main(void)
{
    int *ptr = &matrix[0][0];

    // how is an array allocated in this memory
    printf("*ptr     -> %d\n",*ptr);
    printf("*(ptr+1) -> %d\n",*(ptr+1));
    printf("*(ptr+2) -> %d\n",*(ptr+2));
    printf("*(ptr+3) -> %d\n",*(ptr+3));
    printf("*(ptr+4) -> %d\n",*(ptr+4));
    printf("*(ptr+5) -> %d\n",*(ptr+5));
    printf("*(ptr+6) -> %d\n",*(ptr+6));
    printf("*(ptr+7) -> %d\n",*(ptr+7));
    printf("*(ptr+8) -> %d\n",*(ptr+8));

    printf("elements of array\n");
    for(uint8_t i=0; i<3; i++)
    {
        for(uint8_t j=0; j<3; j++)
        {
            printf("%d ", *(ptr+i*3+j));
        }
        printf("\n");
    }
}