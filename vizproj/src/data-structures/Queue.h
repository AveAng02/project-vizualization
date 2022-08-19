#pragma once

class Queue {

public:

	Queue();

	~Queue();

	bool isEmpty();

	int size();

	int gettop();

	void push(int data);

	void pop();

	int detectError();

	int LENGTH = 100;

	int BREADTH = 100;

	int front;

	int back;

private:

	unsigned int queuelength = 10;

	int* queue;

	int queueERRORstatus;

	void extendLength();

};





