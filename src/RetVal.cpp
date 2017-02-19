#include "RetVal.h"

RetVal::RetVal(ID* id, int* _val, void (*_f)(ID, int*)) : CallStr(id), f(_f), val(_val) {}

void RetVal::run() {
	f(*id, val);
}