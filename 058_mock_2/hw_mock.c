#include <stdio.h>
#include "hw.h"

/* Mock input/state alanları */
int mock_button_state = 0;
int mock_rf_return_value = 0;

/* Call tracking */
int mock_led_on_call_count = 0;
int mock_led_off_call_count = 0;
int mock_rf_send_call_count = 0;

int hw_button_read(void)
{
    return mock_button_state;
}

void hw_led_on(void)
{
    mock_led_on_call_count++;
    printf("MOCK: LED ON\n");
}

void hw_led_off(void)
{
    mock_led_off_call_count++;
    printf("MOCK: LED OFF\n");
}

int hw_rf_send(void)
{
    mock_rf_send_call_count++;
    printf("MOCK: RF SEND\n");
    return mock_rf_return_value;
}