#include "IInput.h"

/* Instance of the IInput Interface */
IInput InputInterface = 
{
    .writeInputValue = IInput_writeInputValue_Impl,
    .readInputValue  = IInput_readInputValue_Impl,
    .writeStatus     = IInput_writeStatus_Impl,
    .readStatus      = IInput_readStatus_Impl
};


/* Static variables for storing current input data */
static float currentInputValue = 0.0f;
static IInput_ResultStatus currentStatus = IINPUT_STATUS_UNKNOW; 

/** Implementations **/
IInput_StatusType IInput_writeInputValue_Impl(float value)
{
    currentInputValue = value;
#ifndef STM32f4
    printf("[IInput] Input value written : %.2f\n",value); 
#endif
    return IINPUT_OK;
}

float IInput_readInputValue_Impl(void)
{
#ifndef STM32f4
    printf("[IInput] Input value read : %.2f\n",currentInputValue); 
#endif
    return currentInputValue;
}

IInput_StatusType IInput_writeStatus_Impl(IInput_ResultStatus status)
{
    currentStatus = status;
#ifndef STM32f4
    printf("[IInput] Input status written: %d\n",status); 
#endif
    return IINPUT_OK;
}

IInput_ResultStatus  IInput_readStatus_Impl(void)
{
#ifndef STM32f4
    printf("[IInput] Input status : %d\n",currentStatus); 
#endif
    return currentStatus;
}
