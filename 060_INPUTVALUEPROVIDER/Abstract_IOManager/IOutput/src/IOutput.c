#include "IOutput.h"


/* Instance of IOutpput Interface */

IOutput OutputInterface =
{
    .writeOutputValue = IOutput_writeOutputValue_Impl,
    .readOutputValue  = IOutput_readOutputValue_Impl,
    .writeStatus      = IOutput_writeStatus_Impl,
    .readStatus       = IOutput_readStatus_Impl
};


/* Static variables for storing current output data */
static float currentOutputValue = 0.0f;
static IOutput_ResultStatus currentStatus = IOUTPUT_STATUS_UNKNOW;


/* Implementations */
IOutput_StatusType IOutput_writeOutputValue_Impl(float value)
{
    currentOutputValue = value;
#ifndef STM32f4
    printf("[IOutput] Output value written : %.2f\n",value); 
#endif
    return IOUTPUT_OK;
}

float IOutput_readOutputValue_Impl(void)
{
#ifndef STM32f4
    printf("[IOutput] Output value read : %.2f\n",currentOutputValue); 
#endif
    return currentOutputValue;
}

IOutput_StatusType IOutput_writeStatus_Impl(IOutput_ResultStatus status)
{
    currentStatus = status;
#ifndef STM32f4
    printf("[IOutput] Output status written : %.2f\n",status); 
#endif
    return IOUTPUT_OK;
}

IOutput_ResultStatus IOutput_readStatus_Impl(void)
{
#ifndef STM32f4
    printf("[IOutput] Output status : %.2f\n",currentStatus); 
#endif
    return currentStatus;
}