#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void changePointer(int **ptr)
{
    static int y = 50;
    *ptr = &y;

}

int main(void)
{
    int x = 10;
    int *p = &x;

    printf("before\n");
    printf("value of p = %d\n",*p);
    printf("p = %d\n",p);

    changePointer(&p);

    printf("after\n");
    printf("value of p = %d\n",*p);
    printf("p = %d\n",p);
    
}