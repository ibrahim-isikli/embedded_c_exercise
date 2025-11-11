#include "counter.h"

int main(void)
{
    counter_t *cntr1 = counter_create("first_c");
    counter_t *cntr2 = counter_create("second_t");

    for(int i=0; i<20; ++i)
    {
        counter_inc(cntr1);
        if(i%2==0)
            continue;
        counter_inc(cntr2);
        counter_print(cntr2);
    }   

   
    counter_print(cntr1);
    return 0;
}
