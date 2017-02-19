/*
 * TimePCB.h
 *
 *  Created on: May 14, 2015
 *      Author: popina
 */

#ifndef _TIMEPCB_H_
#define _TIMEPCB_H_

#include "typedef.h"

class TimePCB {
	int idxPCB, curTime;
public:
	TimePCB(int, int);
	friend bool operator<(const TimePCB& t1, const TimePCB& t2);

	friend bool operator==(const TimePCB& t1, const TimePCB& t2);

	int GetIdx();

	int GetTime();

	TimePCB& operator--();
	TimePCB operator--(int);
	
	void Tick(int t);
};




#endif /* TIMEPCB_H_ */
