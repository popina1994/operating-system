#include "CallStr.h"

#ifndef _NOARGFUN_H_
#define _NOARGFUN_H_

struct NoArgFun : public CallStr{
	
	void (*f)(ID);
	
	NoArgFun(ID*, void (*f)(ID)); 
	virtual void run();
};

#endif
