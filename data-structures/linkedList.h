#pragma once

#include <iostream>

class LinkedList {


public:

    struct node
    {
        

        // data 
        int data;

        // position of next node
        node* nexPos;

    };

    // constructor
    // destructor 
    // copy constructor
    // copy assignment operator
    // move constructor 
    // move assignment operator
    // public member
    // private member


    // return boolean
    // 


    // the API
    int get(int* err) {

        if (success condition) {
            *err = 0;
            return data;
        }
        else {
            *err = -1;
            return 0;
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////////


    // what the user will be doing with the API
    int status = 0;
    int x = list.get(&status);

    if (status) {
        std::cerr << "Error occured";
    }
    else {
        do something with x;
        std::cout << "Success"
    }

    LinkedList() {

    }

    /*
    Write functions for the following features:
     * insert one element to the list
     * remove one element from the list
     * count length of list
     * read specific cell
     * modify the value of specific cell
     * print entire list
     */


     /*
      * Syntax: insert(integer, pointer of type node)
      * Return Value: returns a pointer to the newly created node (The calling function needs to replace the start value by this pointer.)
      * Functionality: adds a node to the present linked list.
      */
    void insertOntop(int new_data);


    /*
     * Syntax: remove(pointer of type node)
     * Return Value: pointer of type node
     * Functionality: removes a node from the linked list.
     */
    void remove();

    void remove(int pos);


    /*
     * length : returns the size of the list
     */
    int size();


    /*
     * Syntax: readData(integer, pointer of type node)
     * Return Value: void
     * Functionality: prints the value in a specific location.
     */
    int get(int position);


    /*
     * Syntax: modData(integer, integer, pointer of type node)
     * Return Value: void
     * Functionality: replaces the sent position with the sent new data.
     */
    void update(int position, int new_data);


    /*
     * Syntax: printLst(pointer of type node)
     * Return Value: void
     * Functionality: prints all the values in the linked list.
     */
    void printLst();


    /*
     * Syntax: removeAll(pointer of type node)
     * Return Value: void
     * Functionality: frees all the allocated memory in the linked list
     */
    void clear();

private:

    node* root = nullptr; // 

    node* traversal = nullptr; // 

};


