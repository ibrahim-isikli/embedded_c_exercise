#include <stdio.h>
#include <stdint.h>

// -----------------------------------------------
// STEP 1: Data  →  what the object HOLDS
// -----------------------------------------------
typedef struct
{
    uint8_t value;                  // the counter number
    void (*increment)(uint8_t *v);  // method: add 1
    void (*reset)    (uint8_t *v);  // method: go back to 0
    void (*print)    (uint8_t  v);  // method: show value
} Counter;


typedef struct 
{
    uint8_t dimmer_state;
    uint8_t dimmer_value;
    void (*dimmer_on)(uint8_t  *state);
    void (*dimmer_off)(uint8_t *state);
    void (*dimmer_set)(uint8_t *value, uint8_t new_value);
}Light_Dimmer;


// -----------------------------------------------
// STEP 2: Functions  →  what the object CAN DO
// -----------------------------------------------
void counter_increment(uint8_t *v)  { *v += 1; }
void counter_reset    (uint8_t *v)  { *v  = 0; }
void counter_print    (uint8_t  v)  { printf("Counter value: %d\n", v); }
void light_dimmer_on(uint8_t *state){ *state = 1; }
void light_dimmer_off(uint8_t *state){ *state = 0; }
void light_dimmer_set(uint8_t *value, uint8_t new_value){ *value = new_value; }

// -----------------------------------------------
// STEP 3: Init  →  connect data and functions
// -----------------------------------------------
void Counter_init(Counter *c)
{
    c->value     = 0;
    c->increment = counter_increment;
    c->reset     = counter_reset;
    c->print     = counter_print;
}

void Light_Dimmer_init(Light_Dimmer *d)
{
    d->dimmer_state = 0;
    d->dimmer_value = 0;
    d->dimmer_on = light_dimmer_on;
    d->dimmer_off = light_dimmer_off;
    d->dimmer_set = light_dimmer_set;
}

// -----------------------------------------------
// STEP 4: Use the object
// -----------------------------------------------
int main(void)
{
    Counter my_counter;
    Counter_init(&my_counter);      // create the object

    Light_Dimmer my_dimmer;
    Light_Dimmer_init(&my_dimmer);

    my_counter.print(my_counter.value);     // 0

    my_counter.increment(&my_counter.value);
    my_counter.increment(&my_counter.value);
    my_counter.increment(&my_counter.value);
    my_counter.print(my_counter.value);     // 3

    my_counter.reset(&my_counter.value);
    my_counter.print(my_counter.value);     // 0

    my_dimmer.dimmer_on(&my_dimmer.dimmer_state);
    my_dimmer.dimmer_set(&my_dimmer.dimmer_value, 50);
    my_dimmer.dimmer_off(&my_dimmer.dimmer_state);

    return 0;
}
