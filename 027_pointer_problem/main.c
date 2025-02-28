#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int add(int a, int b)
{
    return a+b;
}

int multiply(int a, int b)
{
    return a*b;
}

int operate(int x, int y, int (*operation)(int,int))
{
    return operation(x,y);
}


int main(void)
{
    int num1 = 5, num2 = 3;
    int arr[5] = {12,34,65,17,39};
    
    printf("sum:%d\n",operate(num1,num2,add));
    printf("multiply:%d\n",operate(num1,num2,multiply));
    

    return 0;
}