#include "InputValueProvider_private.h"

FUNC(void,dtInputValueProvider_ruInit)(void)
{
    /* get singelton instance */
    dtInputValueProvider* ivp = InputValueProvider_GetInstance();

    /* read output status*/
    ivp->GetOutput().SetStatus( ivp->IOutput->readStatus() );

    if(IOUTPUT_STATUS_FALSE != ivp->GetOutput().GetStatus())
    {
        ivp->GetOutput().SetStatus(IOUTPUT_STATUS_FALSE);
    }
    else
    {
        /*defensive code*/
    }

    ivp->IOutput->writeStatus(ivp->GetOutput().GetStatus());
}
