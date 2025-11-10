#include "counter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct counter {
    uint8_t value;
    char name[32];
};

counter_status_t counter_create(counter_t **out, const char *name)
{
    if (!out) return COUNTER_ERR_NULL;
    counter_t *c = malloc(sizeof(counter_t));
    if (!c) return COUNTER_ERR_ALLOC;
    c->value = 0;
    strncpy(c->name, name ? name : "noname", sizeof(c->name));
    c->name[sizeof(c->name)-1] = '\0';
    *out = c;
    return COUNTER_OK;
}

counter_status_t counter_destroy(counter_t *c)
{
    if (!c) return COUNTER_ERR_NULL;
    free(c);
    return COUNTER_OK;
}

counter_status_t counter_inc(counter_t *c)
{
    if (!c) return COUNTER_ERR_NULL;
    c->value++;
    return COUNTER_OK;
}

counter_status_t counter_dec(counter_t *c)
{
    if (!c) return COUNTER_ERR_NULL;
    if (c->value == 0) return COUNTER_ERR_INVALID;
    c->value--;
    return COUNTER_OK;
}

counter_status_t counter_reset(counter_t *c)
{
    if (!c) return COUNTER_ERR_NULL;
    c->value = 0;
    return COUNTER_OK;
}

counter_status_t counter_print(counter_t *c)
{
    if (!c) return COUNTER_ERR_NULL;
    printf("[%s] value = %d\n", c->name, c->value);
    return COUNTER_OK;
}
