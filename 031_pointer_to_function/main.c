#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int add(int a, int b)
{
    return a+b;
}

int subtract(int a, int b)
{
    return a-b;
}

int multiply(int a, int b)
{
    return a*b;
}

int main(void)
{
    int(*operations[3])(int,int) = {add,subtract,multiply};

    int choice;
    printf("[0]add\n[1]subtract\n[2]multiply\n");
    printf("choose your option:\t");
    scanf("%d",&choice);

    if((choice < 0) || (choice > 2))
    {
        printf("invalid option!\n");
        return 1;
    }

    int result = operations[choice](6,3);
    printf("result:%d\n",result);

    return 0;
}