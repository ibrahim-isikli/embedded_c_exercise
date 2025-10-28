#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef uint8_t (*op_t)(uint8_t a, uint8_t b);

// strategy pattern -> each of these functions is strategy
uint8_t add(uint8_t a, uint8_t b)
{
    return a+b;
}

uint8_t mul(uint8_t a, uint8_t b)
{
    return a*b;
}

uint8_t max2(uint8_t a, uint8_t b)
{
    return (a>b) ? a : b;
}

uint8_t sub(uint8_t a, uint8_t b)
{
    return(a-b);
}

uint8_t min2(uint8_t a, uint8_t b)
{
    return (a<b) ? a:b;
}

// add , mul, max2 -> strategy thus compute is context for implement each of this strategiies

// high order func
uint8_t compute (op_t op, uint8_t x, uint8_t y)
{
    return op(x,y); // In fact  op func is callback func
}



int main(void) 
{
    printf("\noop basics\n\n");

    printf("\n--call part by part\n\n");
    printf("add(3,4) = %d\n",compute(add,3,4));
    printf("mul(3,4) = %d\n",compute(mul,3,4));
    printf("max(3,4) = %d\n",compute(max2,3,4));
    printf("sub(7,4) = %d\n",compute(sub,7,4));
    printf("min(7,6) = %d\n",compute(min2,7,6));

    printf("\n--call into table\n\n");
    op_t table[] = {add,mul,max2,sub,min2};
    const char *names[] = {"add","mul","max","sub","min"};

    for(uint8_t funcs=0; funcs<5; ++funcs)
    {
        uint8_t result = table[funcs](10,5);
        printf("%s(10,5) = %d\n",names[funcs],result);
    }

    return 0;
}
