#include "Queue.h"


Queue::Queue() {

	queue = new int[queuelength];

	front = -1;

	back = -1;

	queueERRORstatus = 0;

}

Queue::~Queue() {

	delete[] queue;
}

bool Queue::isEmpty() {

	if (front == back == -1) {

		return true;

	}

	return false;

}

int Queue::size() {

	if (front == back == -1) {
		return 0;
	}
	
	return back - front;
}

int Queue::gettop() {

	if (front != -1) {

		return queue[front];

	}
}

void Queue::push(int data) {

	if (back + 1 != queuelength) {
		
		back += 1;
		queue[back] = data;
		
	} else {
		extendLength();
		push(data);
	}

}

void Queue::pop() {

	if (front != -1) {
		queue[front] = 0;
		front++;
	}
	else {
		queueERRORstatus = -1;
	}
}

void Queue::extendLength() {

	queuelength *= 2;

	int* newarr = new int[queuelength];

	int counterNew = 0, counterOld = front;

	while (counterOld <= back) {

		newarr[counterNew] == queue[counterOld];
		counterNew++;
		counterOld++;

	}

	int* oldarr = queue;

	queue = newarr;

	delete[] oldarr;

}

int Queue::detectError() {

	return queueERRORstatus;

}

