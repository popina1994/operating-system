/*
 * PCB.h
 *
 *  Created on: May 11, 2015
 *      Author: popina
 */

#ifndef _PCB_H_
#define _PCB_H_

#include "typedef.h"
#include "thread.h"
#include "Queue.h"



// nisam siguran zasto ce DONE, ali saznacemo
enum STATE { MADE = 0, READY = 1, BLOCKED = 2, FINISHED = 4};

class PCB {
	StackSize stackSize;
	Time timeSlice;
	Thread* thread;
	STATE curState;
	unsigned* stack;
	unsigned ss, sp, bp;
	Queue <int> blocked;
	int id;
	
	friend class Kernel;
	friend class Thread;
	friend class SysMode;
	friend class KernSem;
	friend class KernEvent;
public:

	void MakeStack();

	PCB(StackSize _stackSize, Time _timeSlice, Thread* thread);
	~PCB();

};


#endif /* PCB_H_ */
