#include <stdio.h>
#include "event.h"


event_t event_queue[EVENT_QUEUE_SIZE];
int head = 0, tail = 0;

void test_event(void)
{
    printf("\n\n-----------event driven state machine---------------\n\r");
    printf("[sequence of events] pir -> button -> timeout\n\r");
    
    push_event(EVENT_PIR);
    push_event(EVENT_BUTTON);
    push_event(EVENT_TIMEOUT);
    push_event(EVENT_NONE);
   
}

void push_event(event_t e)
{
    event_queue[tail] = e; // tail 4 = e
    tail = (tail+1) % EVENT_QUEUE_SIZE; // tail 4+1=5   5%10 = 5, if lower value 5%4=1 
}

event_t get_event(void)
{
    if(head==tail)
        return EVENT_NONE;

    event_t e = event_queue[head]; // same as like push event
    head = (head+1) % EVENT_QUEUE_SIZE;
    return e;
}