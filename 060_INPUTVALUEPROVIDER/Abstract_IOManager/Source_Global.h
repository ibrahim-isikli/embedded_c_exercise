#ifndef _SOURCE_GLOBAL_
#define _SOURCE_GLOBAL_

#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define FUNC(returnType,functionName) returnType functionName


/* Monotony*/
typedef enum 
{
    MONOTONY_NONE,
    MONOTONY_INCREASING,
    MONOTONY_DECRAEASING
}MonotonType;

/* External Driver Include */
// mcp2515.h, drv8353.h


/* External Software Stack */
// CANopen, Modbus, J1939 etc. 


#endif /* _SOURCE_GLOBAL_ */