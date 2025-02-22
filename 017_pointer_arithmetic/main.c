#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(void)
{
    int arr[]={1,2,3,4,5};
    printf("arr[2]=%d\n",arr[2]);
    printf("*(arr+2)=%d\n",*(arr+2));
    return 0;
}