#ifndef _KERNSEM_H_
#define _KERNSEM_H_

#include "thread.h"
#include "typedef.h"
#include "Queue.h"

class KernSem {
	Queue <PCB*> blocked;
	int val;
public:
	KernSem(int );
	int GetVal();
	virtual void Wait();
	virtual void Signal();
	friend class Kernel;

	static void CreateKernSem(ID* id, int val);
	static void DeleteKernSem(ID id);
	static void GetVal(ID id, int* val); 
	static void Wait(ID id);
	static void Signal(ID id);
};

#endif