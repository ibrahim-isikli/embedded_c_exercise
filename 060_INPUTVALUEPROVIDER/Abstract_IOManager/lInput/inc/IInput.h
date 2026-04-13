#ifndef _IINPUT_H
#define _IINPUT_H

#include "Abstract_IOManager.h"

/* Status type */
typedef enum
{
    IINPUT_OK = 0,
    IINPUT_NOT_OK
}IInput_StatusType;

/* Interface Class */
typedef struct IInput
{
    IInput_StatusType   (*writeInputValue)(float value);
    float               (*readInputValue)(void);
    IInput_StatusType   (*writeStatus)(IInput_ResultStatus status);
    IInput_ResultStatus (*readStatus)(void);
}IInput;

/* Global Instance */
extern IInput InputInterface;

/* Function Prototypes */
IInput_StatusType   IInput_writeInputValue_Impl(float value);
float               IInput_readInputValue_Impl(void);
IInput_StatusType   IInput_writeStatus_Impl(IInput_ResultStatus status);
IInput_ResultStatus IInput_readStatus_Impl(void);


#endif /* _IINPUT_H */