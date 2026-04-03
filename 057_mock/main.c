#include <stdio.h>
#include "app.h"

extern int mock_button_state;

int main() 
{
    printf("\n\n\n---------- MOCK BASIC ---------\n\n");

    printf("->mock test 1\n\n");
    mock_button_state = 0;
    app_run();

    printf("->mock test 2\n\n");
    mock_button_state = 1;
    app_run();

    return 0;
}