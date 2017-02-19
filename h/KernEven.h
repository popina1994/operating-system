#ifndef _KERNEVENT_H_
#define _KERNEVENT_H_

#include "typedef.h"
#include "KernSem.h"
#include "IVTEntry.h"
#include "PCB.h"
typedef unsigned char IVTNo;
class KernEvent {
	KernSem binSem;
	PCB* owner;
	IVTNo ivtNum;
public:
	KernEvent(IVTNo _ivtNum);
	~KernEvent();
	
	void Wait();
	void Signal();
	
	static void MakeKernelEvent(int* idx, IVTNo);
	static void KillKernelEvent(int idx);
	static void Wait(int idx);
	static void Signal(int idx);
	
};

#endif