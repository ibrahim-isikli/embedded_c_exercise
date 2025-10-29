#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// homework
// signature of on_event_td change as uint8_t (*)(voşd*, uint8_t)
// if succesed, Handler must return  1 but failed return 0 and reported by run_task

#define EVENT_CODE_ADC 100
#define EVENT_CODE_TMR 180

typedef enum
{
    API_SUCCESS = 0u,
    API_ERROR

}api_status_td;

// signature for event
typedef api_status_td (*on_event_td)(void *user, uint8_t event_code);

// basic notifier (is that scheduler ?)-> that is not
typedef struct
{
    on_event_td on_event;
    void *user;

}notifier_td;

// from lib: do anything and trigger event
api_status_td run_task(notifier_td *n)
{
    printf("[lib]: i do something bla bla..\n");
    if(n->on_event) 
    {
        if(n->on_event(n->user,EVENT_CODE_ADC) != API_SUCCESS)
            return API_ERROR;
        
         return API_SUCCESS;
    }
}

// from user: context
typedef struct 
{
    uint8_t count;
    const char *name;
}my_ctx;


// user's callback : take back context and use it
api_status_td my_handler(void *user, uint8_t event_code)
{
    my_ctx *ctx = (my_ctx*)user; //back cast 
    uint8_t temp = ctx->count;
    ctx->count++;
    if(temp+1 != ctx->count)
        return API_ERROR;
    printf("[callback] %s: code=%d, count%d\n",ctx->name,event_code,ctx->count);
    return API_SUCCESS;
}



int main(void)
{
    my_ctx ctx = 
    {
        .count = 0,
         .name = "demo"
    };

    notifier_td n =
    {
        .on_event = my_handler,
        .user     = &ctx
    };

    if(run_task(&n) != API_SUCCESS)
    {
        printf("API failed!\n");
    }
    else
    {
        printf("API success!\n");
    }
    
    return 0;
}