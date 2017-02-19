#ifndef _CREATE_S_H_
#define _CREATE_S_H_

#include "CallStr.h"

class CreateSem : public CallStr {
	int val;
	void (*f)(ID*, int);
public:
	CreateSem(ID*, int, void (*f)(ID*, int));
	
	virtual void run();
};

#endif
