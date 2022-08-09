#pragma once

#include <iostream>


class CircularQueue {

public:

	CircularQueue();

	~CircularQueue();

	bool isEmpty();

	int size();

	int front();

	int back();

	void push(int data);

	void pop();


private:

	int* circularqueue;
};