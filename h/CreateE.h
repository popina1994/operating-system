#ifndef _CREATE_E_H_
#define _CREATE_E_H_

#include "CallStr.h"
#include "typedef.h"

typedef unsigned char IVTNo;

class CreateEvent : public CallStr {
	IVTNo ivtNum;
	void (*f)(ID*, IVTNo);
public:
	CreateEvent(ID*, IVTNo, void (*f)(ID*, IVTNo));
	virtual void run();
};

#endif
