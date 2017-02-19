#include "typedef.h"
#include "QueueT.h"

Queue<int>* QueueTimePCB::TickClock(int t) {
	Queue<int>* q = new Queue<int>;

	for (Elem<TimePCB>* it = head; it != NULL; it = it->next) 
		it->info.Tick(t);
	while ( (head != NULL) && (head->info.GetTime() <= 0) ) {
		TimePCB& t = PopFirst();
		q->PushBack(t.GetIdx());
	}

	return q;
}

void QueueTimePCB::ProcessSleep(int idx, Time sleepTime) {
	//printf("Spavaj:%d\n", idx);
	Elem<TimePCB>* prev = NULL;
	for (Elem<TimePCB>* it = head; it != NULL; it = it->next){
		if (sleepTime < it->info.GetTime())
			break;
		prev = it;
	}

	if (head == NULL) { // corner case
		PushBack(TimePCB(idx, sleepTime));
		return;
	}

	if (prev == NULL)
		PushFirst(TimePCB(idx, sleepTime));
	else {
		Elem<TimePCB>* tmp = new Elem<TimePCB>(TimePCB(idx, sleepTime));
		tmp->next = prev->next;
		if (prev->next == NULL)
			tail = tmp;
		prev->next = tmp;
	}
}

