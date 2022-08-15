#include "Stack.h"



// constructor
Stack::Stack() {

	STACKSPACE = 10;

	stack = new int[ STACKSPACE ];

	toppos = -1;

	stackERRORstatus = 0;

}


// destructor 
Stack::~Stack() {

	delete [] stack;

}


bool Stack::isEmpty() {

	if (toppos == -1) {
		return true;
	}
	else {
		return false;
	}

}

int Stack::size() {

	if (toppos >= -1) {
		return toppos + 1;
	}
}

void Stack::extendLength() {

	STACKSPACE *= 2;

	int* newarr = new int[STACKSPACE];

	int* oldarr = stack;

	int counter = toppos;

	for (int i = 0; i < counter; i++) {

		newarr[i] = oldarr[i];

	}

	stack = newarr;

	delete[] oldarr;

}

void Stack::pop() {

	if (toppos != -1) {

		stack[toppos] = 0;
		toppos -= 1;

	}
	else {
		stackERRORstatus = -1;
	}
}

void Stack::push(int data) {

	if (toppos + 1 != STACKSPACE) { // stacklength
		
		toppos += 1;
		stack[toppos] = data;
	}
	else {

		extendLength();
		push(data);
	}
}

int Stack::top() {

	if (toppos != -1) {

		return stack[toppos];

	}
}


int Stack::detectError() {

	return stackERRORstatus;

}
