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

/* BaseClass Definition*/
typedef struct InputValueProvider
{
    /* Interface Pointer */
    IInput* IInput;
    IOutput* IOutput;

    /* Attribute */

    /* Getter/Setter */

    /* toString */

    /* Functional Behaviour */

}dt_InputValueProvider;










#endif /* INPUTVALUEPROVIDER_DEFINITION_H_ */