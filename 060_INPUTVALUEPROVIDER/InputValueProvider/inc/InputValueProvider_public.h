#ifndef INPUTVALUEPROVIDER_PUBLIC_H_
#define INPUTVALUEPROVIDER_PUBLIC_H_

#include "InputValueProvider_definition.h"

/* Constructor external prototypes */
extern void InputValueProvider_CTOR(void);

/* Singelton base class external prototypes */
extern dtInputValueProvider* InputValueProvider_GetInstance(void);

/* Runnable external prtotype */
extern FUNC(void,dtInputValueProvider_ruInit)(void);
extern FUNC(void,dtInputValueProvider_ruRefresh)(void);



#endif /* INPUTVALUEPROVIDER_PUBLIC_H_ */