#include "SysMod.h"
#include "typedef.h"
#include "Kernel.h"

InterrPtr SysMode::oldSysCall = NULL;
InterrPtr SysMode::oldSysDone = NULL;

unsigned SysMode::sysSP = 0;
unsigned SysMode::sysSS = 0;
unsigned* SysMode::sp = NULL;
PCB* SysMode::sysPCB = NULL;
unsigned SysMode::seg = 0;
unsigned SysMode::off = 0;


unsigned* SysMode::savedSPPt = NULL;

unsigned SysMode::savedSS = 0;
unsigned SysMode::savedSP = 0;

int SysMode::idx = -1;
int SysMode::cnt = -1;
unsigned* SysMode::calc = NULL;
CallStr* SysMode::globalStr = NULL;

void SysMode::InitSysMode() {
	sysPCB = new PCB(KERN_SIZE, 0, NULL);
	sysPCB->MakeStack();
	oldSysCall = getvect(0x60);
	oldSysDone = getvect(0x61);
	setvect(0x60, SysCall);
	setvect(0x61, SysDone);
}

void SysMode::ClearSysMode() {
	setvect(0x60, SysMode::oldSysCall);
	setvect(0x61, SysMode::oldSysDone);
	delete sysPCB;
}

void interrupt SysMode::SysCall(...) {
	seg = _BX;
	off = _CX;
	globalStr = (CallStr*)MK_FP(seg, off);
	cnt = 12;	
	savedSP = Kernel::running->sp = _SP;
	savedSS = Kernel::running->ss = _SS;
	sysPCB->stack[KERN_SIZE-cnt] = FP_OFF(sp + cnt);
	savedSPPt = (unsigned*)MK_FP(savedSS, savedSP);
	
	sp = sysPCB->stack + KERN_SIZE - cnt;
	for (idx = 0; idx < cnt; idx ++) 
		sysPCB->stack[KERN_SIZE - 1 - idx] = savedSPPt[cnt - 1 - idx]; 
	
	_SS = FP_SEG(sp);
	_SP = FP_OFF(sp);
	_BP = FP_OFF(sp);
}


void interrupt SysMode::SysDone(...) {
	cnt = 12;

	for (idx = 0; idx < cnt; idx ++)
		savedSPPt[cnt - idx - 1] = sysPCB->stack[KERN_SIZE - idx - 1];
	if (Kernel::dispatchReq) {
		Kernel::dispatchReq = false;
		Kernel::Dispatch();
	}
	_SS = Kernel::running->ss;
	_SP = Kernel::running->sp;
	_BP = Kernel::running->bp;
	delete SysMode::globalStr;
	unlock();
}





