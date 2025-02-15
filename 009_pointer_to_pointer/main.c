#include <stdio.h>
#include <stdlib.h>

void allocateMemory(int **ptr)
{
    *ptr = (int*)malloc(sizeof(int)); // allocate dynamic memory
    if(*ptr == NULL)
    {
        printf("memory not allocated");
        exit(1);
    }
    **ptr = 99;
}


int main(void)
{
    int *p = NULL;
    allocateMemory(&p);
    printf("value stored in dynamic memory: %d\n",*p);
    free(p);
}