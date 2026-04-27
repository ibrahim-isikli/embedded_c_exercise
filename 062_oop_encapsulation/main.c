#include <stdio.h>
#include <stdint.h>

// -----------------------------------------------
// Encapsulation = protect your data.
// Do NOT touch data directly from outside.
// Always use methods (get / set).
// -----------------------------------------------

typedef struct
{
    uint8_t value;   // ← pretend this is PRIVATE (hidden)

    void (*set)(uint8_t *v, uint8_t new_val);  // setter: change value
    uint8_t (*get)(uint8_t v);                  // getter: read value
    void (*print)(uint8_t v);                   // show value
} Counter;

// -----------------------------------------------
// Functions
// -----------------------------------------------
void    counter_set  (uint8_t *v, uint8_t new_val)
{
    if (new_val > 100)   // protect: max value is 100
    {
        printf("ERROR: value %d is too big! Max is 100.\n", new_val);
        return;
    }
    *v = new_val;
}

uint8_t counter_get  (uint8_t v)  { return v; }
void    counter_print(uint8_t v)  { printf("Counter value: %d\n", v); }

// -----------------------------------------------
// Init
// -----------------------------------------------
void Counter_init(Counter *c)
{
    c->value = 0;
    c->set   = counter_set;
    c->get   = counter_get;
    c->print = counter_print;
}

// -----------------------------------------------
// main
// -----------------------------------------------
int main(void)
{
    Counter my_counter;
    Counter_init(&my_counter);

    // GOOD: use the setter method
    my_counter.set(&my_counter.value, 50);
    my_counter.print(my_counter.value);          // 50

    // GOOD: use the getter method
    uint8_t v = my_counter.get(my_counter.value);
    printf("Read with getter: %d\n", v);         // 50

    // setter protects the data → 200 is rejected
    my_counter.set(&my_counter.value, 200);
    my_counter.print(my_counter.value);          // still 50

    // BAD example (do NOT do this in real OOP):
    // my_counter.value = 200;  ← direct access, no protection!

    return 0;
}
