    #include "hw.h"

    void app_run(void)
    {
        if(hw_button_read())
            hw_led_on();
        else
            hw_led_off();
    }