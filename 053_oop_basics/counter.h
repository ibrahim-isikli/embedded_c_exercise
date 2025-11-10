#ifndef COUNTER_H
#define COUNTER_H

#include <stdint.h>

typedef enum {
    COUNTER_OK = 0,
    COUNTER_ERR_NULL,
    COUNTER_ERR_ALLOC,
    COUNTER_ERR_INVALID
} counter_status_t;

typedef struct counter counter_t;

/* yaşam döngüsü */
counter_status_t counter_create(counter_t **out, const char *name);
counter_status_t counter_destroy(counter_t *c);

/* işlemler */
counter_status_t counter_inc(counter_t *c);
counter_status_t counter_dec(counter_t *c);
counter_status_t counter_reset(counter_t *c);
counter_status_t counter_print(counter_t *c);

#endif
