#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



int main(void)
{
    char str[]="embedded systems";
    char *ptr = str;

    while(*ptr !=  '\0') 
    {
        printf("%c",*ptr);
        ptr++;

    }

    return 0;
}
