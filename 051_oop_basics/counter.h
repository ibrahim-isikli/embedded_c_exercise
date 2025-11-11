#ifndef COUNTER_H
#define COUNTER_H

#include <stdint.h>

/* içeriği bilinmeyen, sadece tanımı bilinen tip */
typedef struct counter counter_t;

/* dışarıya sunulan API */
counter_t *counter_create(const char *name);
void       counter_inc(counter_t *c);
void       counter_dec(counter_t *c);
void       counter_reset(counter_t *c);
void       counter_print(counter_t *c);
void       counter_destroy(counter_t *c);

#endif
