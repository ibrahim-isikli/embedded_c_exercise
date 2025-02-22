#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    uint8_t arr[] ={10,20,30,40,50};
    uint8_t *ptr = arr;

    printf("first element: %d\n",*ptr);
    ptr++;
    printf("second element: %d\n",*ptr);
    ptr+=2;
    printf("fourth element: %d\n",*ptr);
    ptr--;
    printf("third element: %d\n",*ptr);

    return 0;
}