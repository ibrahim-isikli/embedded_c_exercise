#include "counter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct counter
{
    uint8_t value;
    char name[32];
};

counter_t *counter_create(const char *name)
{
    counter_t *c = malloc(sizeof(counter_t));
    
    if(!c) 
        return NULL;

    c->value = 0;
    strncpy(c->name,name,sizeof(c->name));
    c->name[sizeof(c->name)-1] = '\0';
    return c;
}

void counter_inc(counter_t *c)
{
    c->value++;
}

void counter_dec(counter_t *c)
{
    c->value--;
}

void counter_reset(counter_t *c)
{
    c->value = 0;
}

void counter_print(counter_t *c)
{
    printf("[%s] value = %d\n",c->name,c->value);
}

void counter_destroy(counter_t *c)
{
    free(c);
}


