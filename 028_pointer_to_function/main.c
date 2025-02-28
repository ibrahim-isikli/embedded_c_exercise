#include <stdlib.h>
#include <stdio.h>

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

int divide(int a, int b)
{
    return (b!=0) ? a/b : 0;
}

int main(void)
{
    // func pointer
    int (*operation)(int,int);

    int choice, num1, num2;

    printf("enter num1:\t");
    scanf("%d",&num1);
    printf("enter num2:\t");
    scanf("%d",&num2);

    printf("----------------MENU----------------\n\n");
    printf("[1]sum\n[2]subtract\n[3]multiply\n[4]divide\n");
    printf("please enter your choice:\t");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:
            operation = add;
            break;
        case 2:
            operation = subtract;
            break;
        case 3:
            operation = multiply;
            break;                    
        case 4:
            operation = divide;
            break;            
        default:
            printf("invalid option!\n");
            return 1;
    }

    printf("result: %d\n",operation(num1,num2));

    return 0;
}