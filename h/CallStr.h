#ifndef _CALLSTR_H_
#define _CALLSTR_H_
#include "typedef.h"
#include "thread.h"



class CallStr {
	static unsigned seg;
	static unsigned off;
	public:
	ID* id; // kad se kreira nesto, najlaksi nacin da se prosledi argument, bez pravljenja koda ogromnim
	
	CallStr(ID*);
	
	virtual void run() = 0; // it will call desired function
	virtual ~CallStr();

	static void WraperRun(CallStr* cs);
};

#endif