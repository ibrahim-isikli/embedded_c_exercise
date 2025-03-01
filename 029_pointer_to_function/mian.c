#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>

int add(int a, int b)
{
    return a+b;
}

int main(void)
{
    int (*funcPtr)(int,int);

    funcPtr = add;

    int result = funcPtr(5,3);

    printf("sum:%d\n",result);

    return 0;
}