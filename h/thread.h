/*
 * thread.h
 *
 *  Created on: May 11, 2015
 *      Author: popina
 */

#ifndef _thread_h_
#define _thread_h_

#include "typedef.h"

typedef unsigned long StackSize;
const StackSize defaultStackSize = 4096;
typedef unsigned int Time;
const Time defaultTimeSlice = 2;
typedef int ID;

class PCB;

class Thread {
public:
	void start();
	void waitToComplete();
	virtual ~Thread();

	static void sleep(Time timeToSleep);
protected:
	friend class PCB;
	Thread (StackSize stackSize = defaultStackSize, Time timeSlice = defaultTimeSlice);
	virtual void run() {}
private:
	ID myPCBID;
	static void wraper(Thread* running);
};

void dispatch();


#endif /* THREAD_H_ */
