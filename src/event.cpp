#include "event.h"
#include "CallStr.h"
#include "NoArgFun.h"
#include "CreateE.h"

Event::Event(IVTNo ivtNum) {
	CallStr* cs = new CreateEvent(&myEVENTID, ivtNum, &KernEvent::MakeKernelEvent);
	CallStr::WraperRun(cs);
}

Event::~Event() {
	CallStr* cs = new NoArgFun(&myEVENTID, &KernEvent::KillKernelEvent);
	CallStr::WraperRun(cs);
}

void Event::wait() {
	CallStr* cs = new NoArgFun(&myEVENTID, &KernEvent::Wait);
	CallStr::WraperRun(cs);
}

void Event::signal() {
	CallStr* cs = new NoArgFun(&myEVENTID, &KernEvent::Signal);
	CallStr::WraperRun(cs);
}