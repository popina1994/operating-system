#include "CallStr.h"
#include "typedef.h"
#include "thread.h"

#ifndef _SLEEPFUN_H_
#define _SLEEPFUN_H_

struct SleepFunction : public CallStr {
	Time t;
	void (*f) (Time);
	
	SleepFunction(ID* , Time, void(*)( Time));
	
	virtual void run();
};

#endif