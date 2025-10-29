#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// homework
// create second context and  call run_task via two differant context with use to notifer struct
// you see keep indepented counter in each output


#define EVENT_CODE_ADC 100
#define EVENT_CODE_TMR 180

// signature for event
typedef void (*on_event_td)(void *user, uint8_t event_code);

// basic notifier 
typedef struct
{
    on_event_td on_event;
    void *user;
}notifier_td;

// from lib: do anything and trigger event
void run_task(notifier_td *n)
{
    printf("[lib]: i do something bla bla..\n");
    if(n->on_event) 
    {
        n->on_event(n->user,EVENT_CODE_ADC);
    }
}

// from user: context
typedef struct 
{
    uint8_t count;
    const char *name;
}my_ctx;

// my second context
typedef struct main
{
    uint8_t count;
    const char *name;
}second_ctx;


// user's callback : take back context and use it
void my_handler(void *user, uint8_t event_code)
{
    my_ctx *ctx = (my_ctx*)user; //back cast 
    ctx->count++;
    printf("[callback] -> | %s |: code=%d, count%d\n",ctx->name,event_code,ctx->count);
}



int main(void)
{
    my_ctx ctx = 
    {
        .count = 0,
        .name = "demo"
    };

    second_ctx ctx_a =
    {
        .count = 0,
        .name = "second"
    };


    notifier_td n =
    {
        .on_event = my_handler,
        .user     = &ctx
    };

    notifier_td a =
    {
        .on_event = my_handler,
        .user     = &ctx_a
    };

    run_task(&n);
    run_task(&a);
    run_task(&n);
    run_task(&n);
    run_task(&a);
    run_task(&n);

    return 0;
}