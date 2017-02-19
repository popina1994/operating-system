#include "CreateW.h"

CreateThreadWraper::CreateThreadWraper(ID* id, StackSize _s, Time _t, Thread* _th, void (*_f)(ID*, StackSize, Time, Thread*)) : CallStr(id), t(_t), 
f(_f), ss(_s), th(_th) {
}

void CreateThreadWraper::run() {
	f(id, ss, t, th);
}