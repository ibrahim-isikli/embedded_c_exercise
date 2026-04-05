#include <stdio.h>
#include "event.h"



int main(void)
{
    test_event();
 
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
                // busy loop
            break;

            default:
                printf("unknown event\n\r\f");
            break;
        }
    }
    return 0;
}