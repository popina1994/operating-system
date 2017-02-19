/*
 * Jezgro.cpp
 *
 *  Created on: May 13, 2015
 *      Author: popina
 */
#include "Kernel.h"
#include "SCHEDULE.H"
#include "Idle.h"
#include "typedef.h"


bool lockFlag = false;
InterrPtr Kernel::oldTimer = NULL;
Idle* Kernel::idle = NULL;
QueueTimePCB Kernel::sleepQueue;
VectorImproved<PCB> Kernel::pcbVector;
VectorImproved<KernSem> Kernel::semVector;
VectorImproved<KernEvent> Kernel::eventVector;
PCB* Kernel::running = NULL;
Time Kernel::globalTimer = 0;
int Kernel::waitClock = 1;
ID Kernel::idleID = 1;
bool Kernel::wokeUp = false;
bool Kernel::dispatchReq = false;

int t = 0;



void Kernel::StartKernel()  {
	PCB* newPCB = new PCB(4048, 0, NULL);
	newPCB->curState = READY;
	running = newPCB;
	newPCB->id = pcbVector.Push(newPCB);
	
	idle = new Idle();
	idle->start();
	
}

void Kernel::StopKernel() {
	Idle::finished = true;
	delete idle;

	pcbVector.Pop(0);
}
 
// prenosi id po referenci, bolji nacin
void Kernel::CreateThread(ID* idx, StackSize stackSize, Time timeSlice, Thread* thread) {
	PCB* newPcb = new PCB(stackSize, timeSlice, thread);
	*idx = pcbVector.Push(newPcb);
	newPcb->id = *idx;
}

void Kernel::StartThread(ID myPCBID) {
	pcbVector[myPCBID]->MakeStack();
	pcbVector[myPCBID]->curState = READY;

	if (pcbVector[idleID] != pcbVector[myPCBID]) {
		Scheduler::put(pcbVector[myPCBID]);
	}
	
}

void Kernel::SleepThread(Time t) {
	running->curState = BLOCKED;
	sleepQueue.ProcessSleep(running->id, t);
	Dispatch();
	
}

void Kernel::WakeThreads(int globalTimer) {
	Queue<int>* q = sleepQueue.TickClock(globalTimer);
	int idx;
	while (!q->Empty()) {
		int idx = q->PopFirst();
		pcbVector[idx]->curState = READY;
		Scheduler::put(pcbVector[idx]); 
	}
	delete q;
}



void Kernel::KillThread(ID myPCBID) {
	pcbVector.Pop(myPCBID);
}

void Kernel::Dispatch() {
	if ( (running->curState == READY) && (running->id!=idleID) )
		Scheduler::put(running);
	running = Scheduler::get();
	if (running == NULL)
		running = pcbVector[idleID];
}

void Kernel::WaitToComplete(ID myPCBID) {
	if (pcbVector[myPCBID]->curState != FINISHED ) {
		pcbVector[myPCBID]->blocked.PushFirst(running->id);
		running->curState = BLOCKED;
		Dispatch();
	}
}

void Kernel::Finish(ID myPCBID) {
	pcbVector[myPCBID]->curState = FINISHED;
	while (!pcbVector[myPCBID]->blocked.Empty()) {
		int idx = pcbVector[myPCBID]->blocked.PopFirst();
		pcbVector[idx]->curState = READY;
		Scheduler::put(pcbVector[idx]);
	}
	running = Scheduler::get();
	if (running == NULL)
		running = pcbVector[idleID];
}


void Kernel::DummyDispatch(ID id) {
	dispatchReq = true;
}

void Kernel::SaveOldTimer() {
	Kernel::oldTimer = getvect(8);
	setvect(8, Kernel::NewTimer);
}

void Kernel::RestoreOldTimer() {
	setvect(8, Kernel::oldTimer);
}

extern void tick();



void interrupt Kernel::NewTimer(...) {
	if (!lockFlag){
		WakeThreads(waitClock);
		waitClock = 0;
	}
	globalTimer++;
	waitClock++;
	
	oldTimer();
	tick();
	if (!lockFlag &&  
	  (( (globalTimer >= running->timeSlice)  && (running->timeSlice != 0) ) || (running == pcbVector[idleID]) ) )    {
		running->sp = _SP;
		running->ss = _SS;
		running->bp = _BP;
			
		Dispatch();
		
		_SS = running->ss;
		_SP = running->sp;
		_BP = running->bp;
		globalTimer = 0;
	}	
}

