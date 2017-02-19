#include "KernSem.h"
#include "Kernel.h"
#include "Scheduler.h"

KernSem::KernSem(int _val) : val(_val) { }

void KernSem::Wait() {
	if (--val < 0) {
		Kernel::running->curState = BLOCKED;
		blocked.PushFirst(Kernel::running);
		Kernel::Dispatch();
	}
}

void KernSem::Signal() { 
	if (val++ < 0) {
		PCB* tmpPCB = blocked.PopFirst();
		tmpPCB->curState = READY;
		Scheduler::put(tmpPCB);
	}
}

int KernSem::GetVal() {
	return val;
}

void KernSem::Wait(ID id) {
	Kernel::semVector[id]->Wait();
}

void KernSem::Signal(ID id) {
	Kernel::semVector[id]->Signal();
}

void KernSem::CreateKernSem(ID* id, int val) {
	KernSem* newKernSem =  new KernSem(val);
	*id = Kernel::semVector.Push(newKernSem);
}

void KernSem::DeleteKernSem(ID id) {
	Kernel::semVector.Pop(id);
}

void KernSem::GetVal(ID id, int* val) {
	*val = Kernel::semVector[id]->val;
}



