#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int changePointer(int **ptr)
{
    **ptr = 42;
}

int main(void)
{
    int num = 10;
    int *ptr = &num;
    int **pp = &ptr;

    printf("address of num = %d\tvalue of num= %d\n",&num,num);
    changePointer(pp);
    printf("address of num = %d\tvalue of num= %d\n",&num,num);

    return 0;

}