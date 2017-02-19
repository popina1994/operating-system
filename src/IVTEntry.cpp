#include "IVTEntry.h"
#include "KernEven.h"

IVTEntry* IVTEntry::IVT[NUM_ENTRIES] = {0};

IVTEntry::IVTEntry(IVTNo _ivtNum, InterrPtr newRoutine) : ivtNum(_ivtNum), event(NULL) {
	oldRoutine = getvect(ivtNum);
	setvect(ivtNum, newRoutine); 
	IVT[ivtNum] = this;
}

IVTEntry::~IVTEntry() {
	(*oldRoutine)();
	setvect(ivtNum, oldRoutine);
	IVT[ivtNum] = NULL;
}

void IVTEntry::SignalEvent() {
	if(event != NULL)event->Signal();
}
