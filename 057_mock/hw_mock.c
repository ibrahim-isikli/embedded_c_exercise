#include <stdio.h>
#include "hw.h"

// should to controlled variable by us
int mock_button_state = 0;

int hw_button_read(void)
{
    printf("MOCK: buttton\n\r\f");
    return mock_button_state;
}

void hw_led_on(void)
{
    printf("MOCK: led on\n\r\f");
}


void hw_led_off(void)
{
    printf("MOCK: led off\n\r\f");
}


void hw_uart_access(void)
{
    printf("uart access\n\r\f");
}