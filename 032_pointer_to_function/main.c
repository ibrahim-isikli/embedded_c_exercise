#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int add(int a, int b)
{
    return a+b;
}

int multiply(int a,int b)
{
    return a*b;
}

void process(int x, int y, int (*operation)(int,int))
{
    printf("result:%d\n",operation(x,y));
}

int main(void)
{
    int choice;
    printf("[1]add\n[2]multiply\n");
    printf("choose option:\t");
    scanf("%d",&choice);

    if(choice == 1)
    {
        process(5,3,add);
    }
    else if(choice == 2)
    {
        process(5,3,multiply);
    }
    else
    {
        printf("invalid options\n");
    }


    return 0;
}