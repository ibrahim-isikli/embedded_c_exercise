#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum
{
    SUM=1,
    EXTRACTION,
    MULTIPLY,

}options;

int add(int a, int b)
{
    return a+b;
}

int multiply(int a, int b)
{
    return a*b;
}

int subtract(int a, int b)
{
    return a-b;
}

int main(void)
{

    int (*funcPtr)(int,int);

    int choice;
    printf("[1]sum\n[2]subtract\n[3]multiply\n");
    printf("choose your option\t");
    scanf("%d",&choice);


    switch(choice)
    {
        case SUM:   
            funcPtr = add;
            break;
        case EXTRACTION:
            funcPtr = subtract;
            break;
        case MULTIPLY:
            funcPtr = multiply;
            break;
        default:
            printf("invalid otion!\n");
            return 1;
    }

    int result = funcPtr(4,2);
    printf("result:\t%d",result);

    return 0;
}