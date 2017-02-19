#ifndef _CREATEW_
#define _CREATEW_

#include "thread.h"
#include "CallStr.h"

struct CreateThreadWraper : public CallStr {
	StackSize ss;
	Time t;
	Thread* th;
	void (*f)(ID*, StackSize, Time, Thread*);
	
	CreateThreadWraper(ID*, StackSize, Time, Thread*, void (*f)(ID*, StackSize, Time, Thread*));
	
	virtual void run();
};

#endif 