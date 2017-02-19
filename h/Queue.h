#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <typedef.h>

template <class T>
struct Elem {
	T info;
	Elem* next;

	Elem(T _info) : info(_info), next(NULL){
	}
};

template <class T>
class Queue {
protected:
	Elem<T>* head,* tail;
public:

	Queue() {
		head = NULL;
		tail = NULL;
	}

	~Queue() {
		for (Elem<T>* it = head; it != NULL; ) {
			Elem<T>* tmp = it;
			it = it->next;
			delete tmp;
		}
	}

	void PushBack(T info) {
		Elem<T>* tmp = new Elem<T>(info);
		if (tail == NULL)
			head = tmp;
		else
			tail->next = tmp;
		tail = tmp;
	}

	void PushFirst(T info) {
		Elem<T>* tmp = new Elem<T>(info);
		tmp->next = head;
		head = tmp;
		if (tail == NULL)
			tail = tmp;
	}

	T PopFirst() {
		Elem<T>* tmpDel = head;
		T tmpRet = head->info;

		head = head->next;

		if (head == NULL)
			tail = NULL;
		delete tmpDel;
		return tmpRet;
	}

	T Top() {
		return head->info;
	}

	bool Empty() {
		return head == NULL;
	}
};


#endif
