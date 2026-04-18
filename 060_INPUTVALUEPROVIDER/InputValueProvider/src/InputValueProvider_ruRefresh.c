#include "InputValueProvider_private.h"

FUNC(void,dtInputValueProvider_ruRefresh)(void)
{
    /* get singleton instance */
    dtInputValueProvider* ivp = InputValueProvider_GetInstance();

    /* read input status from interface and store in instance */
    ivp->GetInput().SetStatus( ivp->IInput->readStatus() );

    if(IINPUT_STATUS_TRUE == ivp->GetInput().GetStatus())
    {
        /* read input value from interface and store in instance */
        ivp->GetInput().SetValue( ivp->IInput->readInputValue() );

        /* pass value to output and mark output as valid */
        ivp->GetOutput().SetValue( ivp->GetInput().GetValue() );
        ivp->GetOutput().SetStatus( IOUTPUT_STATUS_TRUE );
    }
    else
    {
        /* input not available, invalidate output */
        ivp->GetOutput().SetStatus( IOUTPUT_STATUS_FALSE );
    }

    /* write output status and value back through output interface */
    ivp->IOutput->writeStatus( ivp->GetOutput().GetStatus() );
    ivp->IOutput->writeOutputValue( ivp->GetOutput().GetValue() );
}
