#include "semaphor.h"
#include "CallStr.h"
#include "NoArgFun.h"
#include "KernSem.h"
#include "CreateS.h"
#include "RetVal.h"

Semaphore::Semaphore(int _val) {
	CallStr* cs = new CreateSem(&mySEMID, _val, &KernSem::CreateKernSem);	
	CallStr::WraperRun(cs);
}

Semaphore::~Semaphore() {
	CallStr* cs = new NoArgFun(&mySEMID, &KernSem::DeleteKernSem);
	CallStr::WraperRun(cs);
}

void Semaphore::wait() {
	CallStr* cs = new NoArgFun(&mySEMID, &KernSem::Wait);
	CallStr::WraperRun(cs);
}

void Semaphore::signal() {
	CallStr* cs = new NoArgFun(&mySEMID, &KernSem::Signal);
	CallStr::WraperRun(cs);
}

int Semaphore::val() const {
	int ret = 14;
	int semID = mySEMID;
	CallStr* cs = new RetVal(&semID, &ret, &KernSem::GetVal);
	CallStr::WraperRun(cs);
	return ret;
}
