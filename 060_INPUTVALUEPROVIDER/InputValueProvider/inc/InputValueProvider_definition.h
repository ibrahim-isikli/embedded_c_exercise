#ifndef INPUTVALUEPROVIDER_DEFINITION_H_
#define INPUTVALUEPROVIDER_DEFINITION_H_

/* Global Include */
#include "Source_Global.h"
/** Interface Include **/
/* Receiver Port Include */
#include "IInput.h"
/* Sender Port Include */
#include "IOutput.h"

/* Base Return Value */
typedef enum 
{
    IVP_ERR = 0,
    IVP_OK,
    IVP_LOW,
    IVP_HIGH,
    IVP_UNKNOWN = 0xFF    
}dtIvpReturn;


/* CompuMethod alias definition */
typedef dtIvpReturn             dtInputValueProvider_ivpReturn;
typedef IInput_ResultStatus     dtInputValueProvider_inputStatus;
typedef IOutput_ResultStatus    dtInputValueProvider_outputStatus;
typedef float                   dtInputValueProvider_inputValue;
typedef float                   dtInputValueProvider_outputValue;

/* ChildClass Definition */

typedef struct
{
    // attirubutte
    dtInputValueProvider_inputStatus    status;
    dtInputValueProvider_inputValue     value;
    // getter / setter
    dtInputValueProvider_inputStatus (*GetStatus)(void);
    (void)                           (*SetStatus)(dtInputValueProvider_inputStatus status);
    dtInputValueProvider_inputValue  (*GetValue)(void);
    (void)                           (*SetValue)(dtInputValueProvider_inputValue value);
}InputValueProvider_Input;


typedef struct 
{
    // attirubute
    dtInputValueProvider_outputStatus   status;
    dtInputValueProvider_outputValue    value;
    // getter / setter
    dtInputValueProvider_outputStatus (*GetStatus)(void);
    (void)                            (*SetStatus)(dtInputValueProvider_outputStatus status);
    dtInputValueProvider_outputValue  (*GetValue)(void);
    (void)                            (*SetValue)(dtInputValueProvider_outputValue value);
}InputValueProvider_Output;





/* BaseClass Definition*/
typedef struct InputValueProvider
{
    /* Interface Pointer */
    IInput* IInput;
    IOutput* IOutput;

    /* Attribute */
    InputValueProvider_Input input;
    InputValueProvider_Output output;
    
    /* Getter/Setter */
    InputValueProvider_Input  (*GetInput)(void);
    (void)                    (*SetInput)(InputValueProvider_Input input);
    InputValueProvider_Output (*GetOutput)(void);
    (void)                    (*SetOutput)(InputValueProvider_Output output);

    /* toString */
    char* (*toString)(void);
    /* Functional Behaviour */
    dtInputValueProvider_ivpReturn(*checkThreshold)(float value);

}dt_InputValueProvider;










#endif /* INPUTVALUEPROVIDER_DEFINITION_H_ */