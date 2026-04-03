#include <stdio.h>
#include "hw.h"

int hw_button_read(void)
{
    // TODO HAL_GPIO_ReadPin()
    // thats line would be depended HAL
    printf("REAL: button read\n\r");
    return 0; 
}

void hw_led_on(void)
{
    printf("REAL: led on\n\r");
}

void hw_led_off(void)
{
    printf("REAL: led off\n\r");
}