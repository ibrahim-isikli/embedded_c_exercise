#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void changeString(char **str)
{
    *str = "Hi, pointer to pointer";;
}

int main(void)
{
    char *msg ="test message";
    printf("before: %s\n",msg);

    changeString(&msg);

    printf("after: %s\n",msg);

    return 0;
}