#include "counter.h"
#include <stdio.h>

int main(void)
{
  counter_t *c = NULL;
  counter_status_t status;

  status = counter_create(&c,"my_counter");
  
  if(status != COUNTER_OK)
    return -1;

  for(int i=0; i<3; ++i)
    counter_inc(c);

 counter_print(c);
 counter_dec(c);
 counter_print(c);

 counter_reset(c);
 counter_print(c);

 counter_destroy(c);

 return 0;

}
