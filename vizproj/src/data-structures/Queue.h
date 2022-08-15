#pragma once

#include <iostream>


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

private:

	unsigned int queuelength = 10;

	int* queue;

	int front;

	int back;

	int queueERRORstatus;

	void extendLength();

};





