/*
 * Jezgro.h
 *
 *  Created on: May 13, 2015
 *      Author: popina
 */

#ifndef _KERNEL_H_
#define _KERNEL_H_

#include "Vector.h"
#include "PCB.h"
#include "thread.h"
#include "Idle.h"
#include "typedef.h"
#include "QueueT.h"
#include "KernSem.h"
#include "KernEvent.h"

class Kernel {
	friend class SysMode;
	friend class KernSem;
	friend class KernEvent;
	friend class Thread;
	static VectorImproved<PCB> pcbVector;
	static VectorImproved<KernSem> semVector;
	static VectorImproved<KernEvent> eventVector;
	static QueueTimePCB sleepQueue;
	
	static PCB* running;
	static InterrPtr oldTimer;
	static Idle* idle;
	static Time globalTimer;
	static ID idleID;
	static int waitClock;
	static bool wokeUp;
	static bool dispatchReq;
	
	// trebace mi red za uspavane niti
public:
	static void StartKernel(); // odradjeno

	static void StopKernel(); // odradjeno 

	static void CreateThread(ID*, StackSize stackSize, Time timeSlice, Thread*); // odradjeno

	static void StartThread(ID myPCBID); // odradjeno


	static void KillThread(ID myPCBID); 
	
	static void SleepThread(Time t);

	static void Dispatch(); // dummy argument
	
	static void DummyDispatch(ID id);
 
	static void WakeThreads(int); // odradjeno
	static void SaveOldTimer(); // odradjeno
	static void WaitToComplete(ID id);
	
	static void Finish(ID id);

	static void RestoreOldTimer(); // odradjeno 

	static void interrupt NewTimer(...);
};





#endif /* KERNEL_H_ */
