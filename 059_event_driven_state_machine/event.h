#ifndef EVENT_H
#define EVENT_H

typedef enum
{
    EVENT_NONE,
    EVENT_PIR,
    EVENT_BUTTON,
    EVENT_TIMEOUT
} event_t;

#define EVENT_QUEUE_SIZE 10

void test_event(void);
int push_event(event_t e);
event_t get_event(void);


#endif

