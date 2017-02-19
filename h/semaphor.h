#ifndef _SEMAPHORE_H_
#define _SEMAPHORE_H_

#include "thread.h"
#include "typedef.h"

class Semaphore {
	ID mySEMID;
public:
	Semaphore::Semaphore(int _val = 1);
	virtual ~Semaphore();
	
	virtual void wait();
	virtual void signal();
	
	int val() const;
	
};

#endif