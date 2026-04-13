#ifndef _IOUTPUT_H
#define _IOUTPUT_H

#include "Abstract_IOManager.h"

/* Status Type */
typedef enum
{
    IOUTPUT_OK = 1,
    IOUTPUT_NOT_OK
}IOutput_StatusType;

/* Interface Class */
typedef struct IOutput
{
    IOutput_StatusType      (*writeOutputValue)(float value);
    float                   (*readOutputValue)(void);
    IOutput_StatusType      (*writeStatus)(float value);
    IOutput_ResultStatus    (*readStatus)(void);
}IOutput;


/* Global Instance */
extern IOutput   OutputInterface;

/* Function Prototypes */
IOutput_StatusType   IOutput_writeOutputValue_Impl(float value);
float                IOutput_readOutputValue_Impl(void);
IOutput_StatusType   IOutput_writeStatus_Impl(float value);
IOutput_ResultStatus IOutput_readStatus_Impl(void);

#endif /* _IOUTPUT_H */