/*
 * Idle.h
 *
 *  Created on: May 14, 2015
 *      Author: popina
 */

#ifndef IDLE_H_
#define IDLE_H_
#include "thread.h"
#include "typedef.h"
/*
 * Idle.cpp
 *
 *  Created on: May 14, 2015
 *      Author: popina
 */

class Idle : public Thread {
public:
	static bool finished;
	Idle();
	void run();
	~Idle();
};






#endif /* IDLE_H_ */
