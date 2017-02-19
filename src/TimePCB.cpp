/*
/*
 * TimePCB.h
 *
 *  Created on: May 14, 2015
 *      Author: popina
 */

#include "TimePCB.h"

TimePCB::TimePCB(int _idx, int _time) : curTime(_time), idxPCB(_idx) {
}
bool operator<(const TimePCB& t1, const TimePCB& t2) {
	return t1.curTime < t2.curTime;
}

bool operator==(const TimePCB& t1, const TimePCB& t2) {
	return t1.curTime == t2.curTime;
}

int TimePCB::GetIdx() {
	return idxPCB;
}

int TimePCB::GetTime() {
	return curTime;
}

TimePCB& TimePCB::operator--() {
	curTime--;
	return *this;
}

TimePCB TimePCB::operator--(int) {
	TimePCB tmpCopy(*this);
	curTime--;
	return tmpCopy;
}

void TimePCB::Tick(int t) {
	curTime -= t;
}





