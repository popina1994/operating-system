/*
 * QueueTimePCB.h
 *
 *  Created on: May 14, 2015
 *      Author: popina
 */
#ifndef _QUEUET_H_
#define _QUEUET_H_

#include "TimePCB.h"
#include "Queue.h"
#include "typedef.h"
#include "PCB.h"

class QueueTimePCB : public Queue<TimePCB> {
public:
	Queue<int>* TickClock(int); // returns list of all waked up process
	void ProcessSleep(int idx, Time sleepTime);
};

#endif

