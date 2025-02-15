#include <stdio.h>
#include <stdlib.h>

void updateArray(int **arr, int size)
{
    for(int i=0; i<size; i++)
    {
        (*arr)[i] *= 2;
    }

}


int main(void)
{
    int nums[] = {1,2,3,4,5};
    int *ptr = nums;
    int **pptr = &ptr;

    printf("before\n");
    for(int i=0; i<5; i++)
    {
        printf("%d\t",nums[i]);
    }

    updateArray(pptr,5);

    printf("\nafter\n");

    for(int i=0; i<5; i++)
    {
        printf("%d\t",nums[i]);
    }

    return 0;
}