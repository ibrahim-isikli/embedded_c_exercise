#include "app.h"
#include "hw.h"

app_status_t app_run(void)
{
    if (hw_button_read())
    {
        hw_led_on();

        if (hw_rf_send() != 0)
        {
            return APP_RF_ERROR;
        }

        return APP_OK;
    }
    else
    {
        hw_led_off();
        return APP_OK;
    }
}