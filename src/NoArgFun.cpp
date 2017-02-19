#include "NoArgFun.h"

NoArgFun::NoArgFun(ID* _id, void(*_f)(ID)) : CallStr(_id), f(_f) {}

void NoArgFun::run() {
	int t = *id; 
	f(t);
}