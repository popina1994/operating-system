#ifndef _RETVAL_H_
#define _RETVAL_H_
#include "CallStr.h"

class RetVal : public CallStr {
	int* val;
	void (*f)(ID, int*);
public:
	RetVal(ID* id, int* _val, void (*_f)(ID, int*));
	virtual void run();
};

#endif
