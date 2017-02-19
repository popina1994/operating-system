#ifndef _EVENT_H_
#define _EVENT_H_

#include "thread.h"
#include "IVTEntry.h"
#include "KernEven.h"
#include "Kernel.h"

typedef unsigned char IVTNo;
class Event {
public:
	Event(IVTNo);
	~Event();
	
	void wait();
protected:
	friend class KernEvent;
	void signal();
private:
	ID myEVENTID;
};
#define PREPAREENTRY(ivtNum, oldFlag) void interrupt NewRoutine##ivtNum(...);\
		IVTEntry ivtEntry##ivtNum(ivtNum, NewRoutine##ivtNum);\
		void interrupt NewRoutine##ivtNum(...) {\
		ivtEntry##ivtNum.SignalEvent();\
		if (oldFlag) ivtEntry##ivtNum.oldRoutine(); if (!lockFlag)  dispatch(); else Kernel::DummyDispatch(0);  }

#endif