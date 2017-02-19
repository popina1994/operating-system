#include "CreateS.h"

CreateSem::CreateSem(ID* id, int _val, void (*_f)(ID*, int)) : CallStr(id), f(_f), val(_val) {}

void CreateSem::run() {
	f(id, val);
}