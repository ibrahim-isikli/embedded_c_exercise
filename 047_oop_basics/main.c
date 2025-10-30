#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// homework
/*
   add new method : dec
*/
typedef struct counter
{
    uint8_t value;
    const char *name;
    // methods
    void (*give_name)(struct counter *self, char *n);
    void (*inc)(struct counter *self);
    void (*dec)(struct counter *self);
    void (*reset)(struct counter *self);
    void (*print)(struct counter *self);
}counter;


// method implementaition
void counter_give_name(counter *self, const char *n)
{
    self->name = n;
    printf("named : %s\n",self->name);
}

void counter_inc(counter *self)
{
    self->value++;
}

void counter_dec(counter *self)
{
    self->value--;
}

void counter_reset(counter *self)
{
    self->value = 0u;
}

void counter_print(counter *self)
{
    printf("[%s] value = %d\n",self->name,self->value);
}

// init
void counter_init(counter *c)
{
    c->value = 0u;
    c->inc   = counter_inc;
    c->dec   = counter_dec;
    c->reset = counter_reset;
    c->print = counter_print;
    c->give_name = counter_give_name;
}

int main(void)
{

    counter my_counter, your_counter;
    counter_init(&my_counter);
    counter_init(&your_counter);

    my_counter.give_name(&my_counter,"my_counter");
    my_counter.print(&my_counter);
    my_counter.inc(&my_counter);
    my_counter.print(&my_counter);
    my_counter.inc(&my_counter);
    my_counter.inc(&my_counter);
    my_counter.print(&my_counter);
    my_counter.reset(&my_counter);
    my_counter.print(&my_counter);


    your_counter.give_name(&your_counter,"your_counter");
    your_counter.print(&your_counter);
    for(uint8_t i=0; i<5; ++i)
        your_counter.inc(&your_counter);
    your_counter.print(&your_counter);
    your_counter.dec(&your_counter);
    your_counter.print(&your_counter);



    return 0;
}