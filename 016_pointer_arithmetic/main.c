#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{

    uint8_t arr[] = {10,20,30,40,50};
    uint8_t *p1 = &arr[1];
    uint8_t *p2 = &arr[4];

    printf("difference between two pointers:%p\n",p2-p1);

    if(p1 < p2)
    {
        printf("p1 comes before p2\n");
    }

    return 0;
}