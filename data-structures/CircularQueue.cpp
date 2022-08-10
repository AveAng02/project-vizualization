#include "CircularQueue.h"


CircularQueue::CircularQueue() {

	CQLENGTH = 10;
	
	circularqueue = new int[CQLENGTH];

	front = -1;

	back = -1;

	CircularQueueERRORstatus = 0;

}

CircularQueue::~CircularQueue() {

	delete [] circularqueue;

}

bool CircularQueue::isEmpty() {

	if (front == back == -1) {

		return true;

	}

	return false;

}

int CircularQueue::size() {

	if (front == back == -1) {

		return 0;

	}

	if (front < back) {

		return back - front;

	}

	if (front > back) {

		return CQLENGTH - (front - back);

	}
}

int CircularQueue::gettop() {

	if (front > -1) {

		return circularqueue[front];

	}
}

void CircularQueue::push(int data) {

	if (back + 1 - front != CQLENGTH) {

		back = (back + 1) % CQLENGTH;
		circularqueue[back] = data;

	}
	else {

		extendLength();
		push(data);

	}

}

void CircularQueue::pop() {

	if (front > -1) {

		circularqueue[front] = 0;
		front = (front + 1) % CQLENGTH;

	}
	else {

		CircularQueueERRORstatus = -1;

	}
}

void CircularQueue::extendLength() {

	CQLENGTH *= 2;

	int* newarr = new int[CQLENGTH];

	

}

int CircularQueue::detectError() {

	return CircularQueueERRORstatus;

}

