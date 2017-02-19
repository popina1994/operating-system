#include "CallStr.h"
#include "SysMod.h"
#include "typedef.h"

unsigned CallStr::seg = 0;
unsigned CallStr::off = 0;

CallStr::CallStr(ID* _id) : id(_id){
}

CallStr::~CallStr() {
}

void CallStr::WraperRun(CallStr* cs) {
	lock();
	seg = FP_SEG(cs);
	off = FP_OFF(cs); // brzo cemo videti je li puca
	_BX = seg;
	_CX = off;
	asm int 60h; 
	SysMode::globalStr->run();
	asm int 61h;
	
}


