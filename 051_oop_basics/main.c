#include "counter.h"

int main(void)
{
    counter_t *c1 = counter_create("alpha");
    counter_t *c2 = counter_create("beta");

    counter_inc(c1);
    counter_inc(c1);
    counter_print(c1);

    counter_inc(c2);
    counter_dec(c2);
    counter_print(c2);

    counter_destroy(c1);
    counter_destroy(c2);
    return 0;
}
