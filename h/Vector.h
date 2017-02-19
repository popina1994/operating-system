#ifndef _VECTOR_H_
#define _VECTOR_H_


#include "typedef.h"
#include "Queue.h"
#include "PCB.h"


template <class T>
class VectorImproved {
	T* x[MAX_PROCES_START];
	unsigned cnt, size;
	Queue <unsigned> qFree;
public:
	VectorImproved(unsigned _size = MAX_PROCES_START) {
		cnt = 0;
		size = _size;
		for (unsigned idx = 0; idx < size; idx++) {
			x[idx] = NULL;
			qFree.PushBack(idx);
		}
	}

	~VectorImproved() {
		for (int idx = 0; idx < size; idx ++) if(x[idx]!=NULL)
			delete x[idx];
	}

	 int Push(T* par) {
		cnt++;

		int idx = qFree.PopFirst();
		x[idx] = par;
		return idx;
	}

	void Pop(int idx) {
		delete x[idx];
		x[idx] = NULL;
		qFree.PushBack(idx);
		cnt --;
	}

	T*& operator[](int idx) {
		return x[idx];
	}

};

#endif /* VECTORIMPROVED_H_ */
