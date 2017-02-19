/*
 * thread.cpp
 *
 *  Created on: May 13, 2015
 *      Author: popina
 */
#include "thread.h"
#include "Kernel.h"
#include "PCB.h"
#include "CallStr.h"
#include "CreateW.h"
#include "SleepFun.h"
#include "NoArgFun.h"


Thread::Thread(StackSize stackSize, Time timeSlice) {
	CallStr* cs = new CreateThreadWraper(&myPCBID, stackSize, timeSlice, this, &Kernel::CreateThread);
	CallStr::WraperRun(cs);
}


Thread::~Thread() {
	waitToComplete();
	CallStr* cs = new NoArgFun(&myPCBID, &Kernel::KillThread);
	CallStr::WraperRun(cs);
}

void Thread::start() {
	CallStr* cs = new NoArgFun(&myPCBID, &Kernel::StartThread);
	CallStr::WraperRun(cs);
}

void Thread::wraper(Thread* running) {
	running->run();
	CallStr* cs = new NoArgFun(&running->myPCBID, &Kernel::Finish);
	CallStr::WraperRun(cs);
}

void dispatch() {
	CallStr* cs = new NoArgFun(0, &Kernel::DummyDispatch);
	CallStr::WraperRun(cs);
}

void Thread::sleep(Time timeToSleep) {
	CallStr* cs = new SleepFunction(NULL, timeToSleep, &Kernel::SleepThread);
	CallStr::WraperRun(cs);
}

void Thread::waitToComplete() {
	CallStr* cs = new NoArgFun(&myPCBID, &Kernel::WaitToComplete);
	CallStr::WraperRun(cs);
}


