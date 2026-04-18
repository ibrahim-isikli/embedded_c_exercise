#include "InputValueProvider_public.h"

int main(void)
{
    InputValueProvider_CTOR(); /* Constructor Call */
    dtInputValueProvider* ivp = InputValueProvider_GetInstance(); /* Get Instance */

    /* PRE INITIALIZATION */
    printf("PRE INITIALIZATION: %s\n", ivp->toString());

    return 0;
}