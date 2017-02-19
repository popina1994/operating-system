#ifndef _IVTENTRY_H_
#define _IVTENTRY_H_

#include "thread.h"
#include "typedef.h"

typedef unsigned char IVTNo;
const int NUM_ENTRIES = 256;

class KernEvent;

class IVTEntry {
	IVTNo ivtNum;
	KernEvent* event;
	static IVTEntry* IVT[NUM_ENTRIES];
	friend class KernEvent;
public:
	IVTEntry(IVTNo, InterrPtr);
	~IVTEntry();
	void SignalEvent();
	InterrPtr oldRoutine;
};

#endif