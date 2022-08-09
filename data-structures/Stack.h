#pragma once

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

    void pop();

    void push(int data);

    int top();

    int stackERRORstatus;

    // private member
private:

    int STACKSPACE;

    int* stack;

    int toppos;

};

