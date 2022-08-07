#pragma once

#include <iostream>

class linkedList {

public:

    struct node
    {
        // data 
        int data;
        // position of next node
        node* nexPos;
    };

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
    node* insert(int new_data, node* old_pointer);


    /*
     * Syntax: remove(pointer of type node)
     * Return Value: pointer of type node
     * Functionality: removes a node from the linked list.
     */
    node* remove(node* startPosition);


    /*
     * Syntax: length(pointer of type node)
     * Return Value: void
     * Functionality: prints the length of the linked list.
     */
    void length(node* starting_point);


    /*
     * Syntax: readData(integer, pointer of type node)
     * Return Value: void
     * Functionality: prints the value in a specific location.
     */
    void readData(int position, node* startPos);


    /*
     * Syntax: modData(integer, integer, pointer of type node)
     * Return Value: void
     * Functionality: replaces the sent position with the sent new data.
     */
    void modData(int position, int new_data, node* startPos);


    /*
     * Syntax: printLst(pointer of type node)
     * Return Value: void
     * Functionality: prints all the values in the linked list.
     */
    void printLst(node* starting_point);


    /*
     * Syntax: removeAll(pointer of type node)
     * Return Value: void
     * Functionality: frees all the allocated memory in the linked list
     */
    void removeAll(node* starting_point);

};


