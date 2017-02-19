#include "SleepFun.h"

SleepFunction::SleepFunction(ID* _id, Time _t, void (*_f)(Time)) : CallStr(_id), t(_t), f(_f) {}

void SleepFunction::run() {
	f(t);
}