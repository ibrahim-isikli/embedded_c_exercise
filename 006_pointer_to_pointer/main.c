#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void) 
{
    int a = 10; // variable
    int*p = &a; // pointer (address of variable)
    int *pp =&p; // pointer to pointer (address of variable's address)

    printf("value of a:            %d\n",a);
    printf("value indicated by p:  %d\n",*p);
    printf("value indicated by pp: %d\n",*pp);
    printf("\n\n");
    printf("addres of a:           %d\n",(void*)&a);
    printf("addres of p:           %d\n",(void*)&p);
    printf("addres of pp:          %d\n",(void*)&pp);
    printf("\n\n");
    printf("&a == p == *pp\n");
    printf("%d == %d == %d\n",&a,p,*pp);

    
    return 0;
}



#if 0

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void changePointer(int **)
{

}

int main(void)
{

    int x = 10;
    int *p = &x;

    printf("value   of p: %d\n",*p);
    printf("address of p: %d\n",p);

    changePointer(&p);

}

#endif