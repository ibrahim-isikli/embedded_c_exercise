#include "InputValueProvider_private.h"

/* Instance Definition */
static dtInputValueProvider Instance;

/* Getter-Setter Impl Base Class */
InputValueProvider_Input    InputValueProvider_GetInput_Impl(void);
void                        InputValueProvider_SetInput_Impl(InputValueProvider_Input input);
InputValueProvider_Output   InputValueProvider_GetOutput_Impl(void);
void                        InputValueProvider_SetOutput_Impl(InputValueProvider_Output output);

/* Getter-Setter Impl Child Class*/
dtInputValueProvider_inputStatus    InputValueProvider_GetStatus_Impl(void);
void                                InputValueProvider_SetStatus_Impl(dtInputValueProvider_inputStatus status);
dtInputValueProvider_inputValue     InputValueProvider_GetValue_Impl(void);
void                                InputValueProvider_SetValue_Impl(dtInputValueProvider_inputValue value);
dtInputValueProvider_outputStatus   InputValueProvider_GetStatus_Impl(void);
void                                InputValueProvider_SetStatus_Impl(dtInputValueProvider_outputStatus status);
dtInputValueProvider_outputValue    InputValueProvider_GetValue_Impl(void);
void                                InputValueProvider_SetValue_Impl(dtInputValueProvider_outputValue value);

/* toString - toString(helper) */
char* (*toString)(void);
/* Constructor */

/* Child Class Constructor(CTOR) */

/* Base Class Constructor(CTOR) */

/* Singelton Instance Getter */




///////////////////////////////////////////////////


/* Functional Behaviour Impl */
