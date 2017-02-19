#include "CreateE.h"

CreateEvent::CreateEvent(ID* id, IVTNo _ivtNum, void (*_f)(ID*, IVTNo)) : CallStr(id), f(_f), ivtNum(_ivtNum) {}

void CreateEvent::run() {
	f(id, ivtNum);
}