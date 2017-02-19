#include "Idle.h"
#include "typedef.h"
#include "thread.h"

bool Idle::finished = false;

Idle::Idle() : Thread(1000, 0) {}
void Idle::run() {
	long idx = 0;
	while (!finished) { 
		if (idx == 1000000) {
			if (DEBUG) {
				idx = 0;
			}
		}
		idx++;
	}
};

void Idle::~Idle() {waitToComplete();}

