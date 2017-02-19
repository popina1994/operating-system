#include <dos.h>
#include "PCB.h"
#include "Kernel.h"
#include <iostream.h>

PCB::PCB(StackSize _stackSize, Time _timeSlice, Thread* _thread) : stackSize(_stackSize),
		timeSlice(_timeSlice),thread(_thread), curState(MADE), stack(NULL) {
}

PCB::~PCB() {
	if (stack != NULL)
		delete [] stack;
}

void PCB::MakeStack() {
	stack = new unsigned[stackSize];
	stack[stackSize-1] = FP_SEG(thread);
	stack[stackSize-2] = FP_OFF(thread);
	stack[stackSize-5] = 0x200;
	stack[stackSize-6] = FP_SEG(Thread::wraper);
	stack[stackSize-7] = FP_OFF(Thread::wraper);
	this->ss = FP_SEG(stack + stackSize - 16);
	this->sp = FP_OFF(stack + stackSize - 16);
	this->bp = FP_OFF(stack + stackSize - 16);
}






