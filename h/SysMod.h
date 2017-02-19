/*
 * SysMode.h
 *
 *  Created on: May 15, 2015
 *      Author: popina
 */

#ifndef _SYSMODE_H_
#define _SYSMODE_H_

#include "typedef.h"
#include "PCB.h"
#include "CallStr.h"

const int KERN_SIZE = 1000;


class SysMode {
	static InterrPtr oldSysCall;
	static InterrPtr oldSysDone;
	static PCB* sysPCB;
	static unsigned* sp;
	static unsigned sysSP;
	static unsigned sysSS;
	static unsigned seg;
	static unsigned off;

	static unsigned* SysMode::savedSPPt;
	
	static unsigned savedBP;
	static unsigned savedSS;
	static unsigned savedSP;
	
	static int cnt;
	static int idx;
	static unsigned* calc;
	friend class Kernel;
public:
	static CallStr* globalStr;
	static void InitSysMode();
	static void ClearSysMode();
	
	static void interrupt SysCall(...);
	static void interrupt SysDone(...);
};



#endif /* SYSMODE_H_ */
