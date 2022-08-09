

#include <iostream>


class Stack {

public:

    Stack();

    ~Stack();

    // copy constructor
    
    // copy assignment operator
    // move constructor 
    // move assignment operator
    // public member

    bool isEmpty();

    int size();

    void extendLength();

    void pop();

    void push(int data);

    int top();

    int detectError();

    // private member
private:

    unsigned int STACKSPACE;

    int* stack;

    int toppos;

    int stackERRORstatus;

};

