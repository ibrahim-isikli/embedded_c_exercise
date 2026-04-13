#ifndef ABSTRACT_IOMANAGER_H
#define ABSTRACT_IOMANAGER_H

#include "Source_Global.h" 
/*------- IInput Interface -------*/

/* IInput : Generic Status Flag    */
typedef enum
{
    IINPUT_STATUS_TRUE      = 0,
    IINPUT_STATUS_FALSE     = 1,
    IINPUT_STATUS_UNKNOW    = 0xFF
}IInput_ResultStatus;


/* IInput : Compu Method Flag      */
typedef uninon
{
    float data;
    struct 
    {
        uint32_t raw_bits;
    }asBits;
}cmIInputResult;

/* IInput : Data Constraint Flag   */
typedef struct 
{
    float upperLimit;
    float lowerLimit;
    MonotonType monotony;
}dcIInputResult;


/* ------- IOutput Interface ------- */

/* IOutput : Generic Status Flag    */
typedef enum
{
    IOUTPUT_STATUS_TRUE      = 0,
    IOUTPUT_STATUS_FALSE     = 1,
    IOUTPUT_STATUS_UNKNOW    = 0xFF
}IOutput_ResultStatus;

/* IOutput : Compu Method Flag      */
typedef uninon
{
    float data;
    struct 
    {
        uint32_t raw_bits;
    }asBits;
}cmIOutputResult;

/* IOutput : Data Constraint Flag   */
typedef struct 
{
    float upperLimit;
    float lowerLimit;
    MonotonType monotony;
}dcIOutputResult;

#endif /* ABSTRACT_IO_MANAGER_H*/