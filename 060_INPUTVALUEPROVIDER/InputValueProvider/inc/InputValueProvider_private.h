#ifndef INPUTVALUEPROVIDER_PRIVATE_H_
#define INPUTVALUEPROVIDER_PRIVATE_H_

#include "InputValueProvider_definition.h"

/* Constructor Prototype */
void InputValueProvider_CTOR(void);

// if user want to multiple (changeable) components use that line
// that is super class construct
//void InputValueProvider_CTOR(dtInputValueProvider input_ctr);

/* Singelton base class getter */
dtInputValueProvider* InputValueProvider_GetInstance(void);

/* Runnables */
FUNC(void,dtInputValueProvider_ruInit)(void);
FUNC(void,dtInputValueProvider_ruRefresh)(void);

/* Local method definitions*/
dtInputValueProvider_ivpReturn InputValueProvider_checkThreshold_Impl(float value);

#endif /* INPUTVALUEPROVIDER_PRIVATE_H_ */