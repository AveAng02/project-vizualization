#include "Stack.h"



// constructor
Stack::Stack() {

	STACKSPACE = 10;

	stack = new int(STACKSPACE * sizeof(int));

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

	if (toppos + 1 != 10) { // stacklength
		
		toppos += 1;
		stack[toppos] = data;
	}
}

int Stack::top() {

	if (toppos != -1) {

		return stack[toppos];

	}
}
