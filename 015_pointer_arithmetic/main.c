#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(void)
{
    uint8_t x = 5;
    uint8_t *p = &x;

    printf("address p: %p\n",p);
    p++;
    printf("after p++: %p\n",p);
    printf("1 byte increment (uint8_t)\n");


    uint16_t y = 5;
    uint16_t *p2 = &y;
    printf("address p2: %p\n",p2);
    p2++;
    printf("after p2++: %p\n",p2);
    printf("2 byte increment (uint16_t)\n");

    char z = 5;
    char *p3 = &z;
    printf("address p3: %p\n",p3);
    p3++;
    printf("after p3++: %p\n",p3);
    printf("1 byte increment (char)\n");

    return 0;

}