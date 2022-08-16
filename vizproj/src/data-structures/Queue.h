#pragma once

#include <iostream>

#include "display-variables.h"

#include "graphics.h"

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

	void drawQueue();

private:

#define LENGTH 100

#define BREADTH 100

	unsigned int queuelength = 10;

	int* queue;

	int front;

	int back;

	int queueERRORstatus;

	void extendLength();

};





