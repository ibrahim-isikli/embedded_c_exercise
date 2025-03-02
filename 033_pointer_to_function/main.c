#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int add(int a, int b)
{
    return a+b;
}

int main(void)
{
    int (**funcPtr)(int,int) = malloc(sizeof(int(*)(int,int)));

    if(funcPtr == NULL)
    {
        printf("memory allocation failed!\n");
        return 1;
    }

    *funcPtr = add;

    int result = (*funcPtr)(10,15);
    printf("result: %d\n", result); 
    free(funcPtr);

    return 0;
}