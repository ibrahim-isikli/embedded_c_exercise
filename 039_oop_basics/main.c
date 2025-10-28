#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define DEFAULT_DOT_VAL 12

// funcs protoypes
void writer_dot(uint8_t x, uint8_t y);

typedef struct 
{
    uint8_t x,y;
    void (*writer_dot)(uint8_t,uint8_t);
}dot_td;


void writer_dot(uint8_t x, uint8_t y)
{
    printf("Line: (%d,%d)\n",x,y);
}

int main(void)
{
    printf("oop basics\n");

    dot_td my_dot1;
    my_dot1.x = DEFAULT_DOT_VAL;
    my_dot1.y = DEFAULT_DOT_VAL;
    my_dot1.writer_dot = writer_dot; // assignmet pointer of func

    my_dot1.writer_dot(my_dot1.x,my_dot1.y);
    return 0;
}