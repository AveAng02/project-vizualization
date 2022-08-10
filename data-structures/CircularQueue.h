

#include <iostream>


class CircularQueue {

public:

	CircularQueue();

	~CircularQueue();

	bool isEmpty();

	int size();

	int gettop();

	void push(int data);

	void pop();

	void extendLength();

	int detectError();

private:

	int CQLENGTH;

	int* circularqueue;

	int front;

	int back;

	int CircularQueueERRORstatus;

};