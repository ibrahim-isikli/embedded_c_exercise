#include <stdio.h>
#include "event.h"



int main(void)
{
    test_event();
    push_event(EVENT_PIR);
    push_event(EVENT_BUTTON);
    push_event(EVENT_TIMEOUT);
 
    while(1)
    {
        event_t e = get_event();
        switch (e)
        {
            case EVENT_PIR:
                printf("event pir\n\r\f");
            break;
            
            case EVENT_BUTTON:
                printf("event button\n\r\f");
            break;

            case EVENT_TIMEOUT:
                printf("event timeout\n\r\f");
            break;

            case EVENT_NONE:
            break;

            default:
                printf("unknow event\n\r\f");
            break;
        }
    }
    return 0;
}