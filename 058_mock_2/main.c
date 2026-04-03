#include <stdio.h>
#include "app.h"

/* Mock değişkenleri dışarıdan alınır */
extern int mock_button_state;
extern int mock_rf_return_value;

extern int mock_led_on_call_count;
extern int mock_led_off_call_count;
extern int mock_rf_send_call_count;

static void mock_reset_all(void)
{
    mock_button_state = 0;
    mock_rf_return_value = 0;

    mock_led_on_call_count = 0;
    mock_led_off_call_count = 0;
    mock_rf_send_call_count = 0;
}

static void print_test_result(const char *test_name, int condition)
{
    if (condition)
    {
        printf("[PASS] %s\n", test_name);
    }
    else
    {
        printf("[FAIL] %s\n", test_name);
    }
}

int main(void)
{
    app_status_t result;

    /* TEST 1: Buton basili degil */
    mock_reset_all();
    mock_button_state = 0;

    result = app_run();

    print_test_result("T1 status APP_OK", result == APP_OK);
    print_test_result("T1 led_off called once", mock_led_off_call_count == 1);
    print_test_result("T1 led_on not called", mock_led_on_call_count == 0);
    print_test_result("T1 rf_send not called", mock_rf_send_call_count == 0);

    printf("\n");

    /* TEST 2: Buton basili, RF basarili */
    mock_reset_all();
    mock_button_state = 1;
    mock_rf_return_value = 0;

    result = app_run();

    print_test_result("T2 status APP_OK", result == APP_OK);
    print_test_result("T2 led_on called once", mock_led_on_call_count == 1);
    print_test_result("T2 led_off not called", mock_led_off_call_count == 0);
    print_test_result("T2 rf_send called once", mock_rf_send_call_count == 1);

    printf("\n");

    /* TEST 3: Buton basili, RF hata */
    mock_reset_all();
    mock_button_state = 1;
    mock_rf_return_value = -1;

    result = app_run();

    print_test_result("T3 status APP_RF_ERROR", result == APP_RF_ERROR);
    print_test_result("T3 led_on called once", mock_led_on_call_count == 1);
    print_test_result("T3 rf_send called once", mock_rf_send_call_count == 1);

    return 0;
}