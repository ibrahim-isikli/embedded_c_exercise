#include "InputValueProvider_private.h"

/* Instance Definition */
static dtInputValueProvider instance;

/* Getter-Setter Impl Base Class */
InputValueProvider_Input    InputValueProvider_GetInput_Impl(void)
{
    return instance.input;
}

void                        InputValueProvider_SetInput_Impl(InputValueProvider_Input input)
{
    instance.input = input;
}

InputValueProvider_Output   InputValueProvider_GetOutput_Impl(void)
{
    return instance.output;
}

void                        InputValueProvider_SetOutput_Impl(InputValueProvider_Output output)
{
    instance.output = output; 
}

/* Getter-Setter Impl Child Class*/
dtInputValueProvider_inputStatus    InputValueProvider_GetInputStatus_Impl(void)
{
    return instance.input.status;
}

void                                InputValueProvider_SetInputStatus_Impl(dtInputValueProvider_inputStatus status)
{
    instance.input.status = status;
}

dtInputValueProvider_inputValue     InputValueProvider_GetInputValue_Impl(void)
{
    return instance.input.value;
}

void                                InputValueProvider_SetInputValue_Impl(dtInputValueProvider_inputValue value)
{
    instance.input.value = value;
}

dtInputValueProvider_outputStatus   InputValueProvider_GetOutputStatus_Impl(void)
{
    return instance.output.status;
}

void                                InputValueProvider_SetOutputStatus_Impl(dtInputValueProvider_outputStatus status)
{
    instance.output.status = status;
}

dtInputValueProvider_outputValue    InputValueProvider_GetOutputValue_Impl(void)
{
    return instance.output.value;
}

void                                InputValueProvider_SetOutputValue_Impl(dtInputValueProvider_outputValue value)
{
    instance.output.value = value;
}

/* toString - toString(helper) */
const char* getStringFromIvpReturn(dtInputValueProvider_ivpReturn value)
{
    switch (value)
    {
        case IVP_OK     : return "OK";
        case IVP_ERR    : return "ERR";
        case IVP_HIGH   : return "HIGH";
        case IVP_LOW    : return "LOW";
        default         : return "UNKNOWN";
    }
}

const char* getStringFromInputStatus(dtInputValueProvider_inputStatus value)
{
    switch (value)
    {
        case IINPUT_STATUS_TRUE     : return "TRUE";
        case IINPUT_STATUS_FALSE    : return "FALSE";
        default                     : return "UNKNOWN";
    }
}

const char* getStringFromOutputStatus(dtInputValueProvider_outputStatus value)
{
    switch (value)
    {
        case IOUTPUT_STATUS_TRUE     : return "TRUE";
        case IOUTPUT_STATUS_FALSE    : return "FALSE";
        default                      : return "UNKNOWN";
    }
}

char* InputValueProvider_toString_Impl(void)
{
    dtInputValueProvider* self = InputValueProvider_GetInstance();
    dtInputValueProvider_ivpReturn status = self->checkThreshold(self->GetInput().GetValue()); 
    char* str = (char*)malloc(256);
    if(str == NULL)
        return strdup("Memory allocation failed!\n");
    else
    {
        printf("[InputValueProvider] Input: %2.f, InputStatus:%s,Output: %2.f, OutputStatus:%s, ThresholdStatus:%s\n",
        self->GetInput().GetValue(),
        getStringFromInputStatus(self->GetInput().GetStatus()),
        self->GetOutput().GetValue(),
        getStringFromOutputStatus(self->GetOutput().GetStatus()),
        getStringFromIvpReturn(status));
    }
}

/* Constructor */

/* Child Class Constructor(CTOR) */
void InputValueProvider_Input_CTOR(void)
{
    instance.input.status = IINPUT_STATUS_UNKNOW;
    instance.input.value  = 0.0f;
    instance.input.GetStatus = InputValueProvider_GetInputStatus_Impl;
    instance.input.SetStatus = InputValueProvider_SetInputStatus_Impl;
    instance.input.GetValue  = InputValueProvider_GetInputValue_Impl;
    instance.input.SetValue  = InputValueProvider_SetInputValue_Impl;
}

void InputValueProvider_Output_CTOR(void)
{
    instance.output.status = IOUTPUT_STATUS_UNKNOW;
    instance.output.value  = 0.0f;
    instance.output.GetStatus = InputValueProvider_GetInputStatus_Impl;
    instance.output.SetStatus = InputValueProvider_SetInputStatus_Impl;
    instance.output.GetValue  = InputValueProvider_GetInputValue_Impl;
    instance.output.SetValue  = InputValueProvider_SetInputValue_Impl;
}

/* Base Class Constructor(CTOR) */
void InputValueProvider_CTOR(void)
{
    /* child class CTOR */
    InputValueProvider_Input_CTOR();
    InputValueProvider_Output_CTOR();

    /* Interface Connection */
    instance.IInput = &InputInterface;
    instance.IOutput= &OutputInterface;
    
    /* Main Class Getter/Setter */
    instance.GetInput =InputValueProvider_GetInput_Impl;
    instance.SetInput = InputValueProvider_SetInput_Impl;
    instance.GetOutput = InputValueProvider_GetOutput_Impl;
    instance.SetOutput = InputValueProvider_SetOutput_Impl;
    
    /* toString Asign */
    instance.toString = InputValueProvider_toString_Impl;

    /* Behaviour Asign */
    instance.checkThreshold = InputValueProvider_checkThreshold_Impl;

}

/* Singelton Instance Getter */
dtInputValueProvider* InputValueProvider_GetInstance(void)
{
    return &instance;
}




///////////////////////////////////////////////////


/* Functional Behaviour Impl */
dtInputValueProvider_ivpReturn InputValueProvider_checkThreshold_Impl(float value) 
{
    if(value <=10.0f)
        return IVP_LOW;
    else if (value > 10.0f)
        return IVP_HIGH;
    else
        return IVP_ERR;
}