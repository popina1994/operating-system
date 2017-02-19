#include "KernEven.h"
#include "Kernel.h"

KernEvent::KernEvent(IVTNo _ivtNum) : binSem(0), ivtNum(_ivtNum) {
	owner = Kernel::running;
	IVTEntry::IVT[ivtNum]->event = this;
}

KernEvent::~KernEvent() {
	IVTEntry::IVT[ivtNum]->event = NULL;
}

void KernEvent::Wait() {
		if (Kernel::running != owner)
			return;
		asm pushf;
		asm cli;
		binSem.Wait();
		asm popf;
}

void KernEvent::Signal() {
	asm pushf;
	asm cli;
	binSem.Signal();
	asm popf;
}

void KernEvent::MakeKernelEvent(int* idx, IVTNo ivtNum) {
	KernEvent* tmp = new KernEvent(ivtNum);
	*idx = Kernel::eventVector.Push(tmp);
}

void KernEvent::KillKernelEvent(int idx) {
	Kernel::eventVector.Pop(idx);
}

void KernEvent::Wait(int idx) {
	Kernel::eventVector[idx]->Wait();
}

void KernEvent::Signal(int idx) {
	Kernel::eventVector[idx]->Signal();
}