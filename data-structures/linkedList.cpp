#include "linkedList.h"


struct linkedList::node
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
linkedList::node* linkedList::insert(int new_data, node* old_pointer)
{
    node* temp = (node*)malloc(sizeof(node));
    (*temp).data = new_data;
    (*temp).nexPos = old_pointer;
    return temp;
}


/*
 * Syntax: remove(pointer of type node)
 * Return Value: pointer of type node
 * Functionality: removes a node from the linked list.
 */
linkedList::node* linkedList::remove(node* startPosition)
{
    if(startPosition != NULL)
    {
        node* temp = (*startPosition).nexPos;
        std::cout << (*startPosition).data << " getting freed......" << std::endl;
        free(startPosition);
        return temp;
    }
    else
    {
        std::cout << "No nodes to be removed......." << std::endl;
        return NULL;
    }
}


/*
 * Syntax: length(pointer of type node)
 * Return Value: void
 * Functionality: prints the length of the linked list.
 */
void linkedList::length(node* starting_point)
{
    int count = 0;

    while(starting_point != NULL)
    {
        count++;
        starting_point = (*starting_point).nexPos;

    } 

    std::cout << "The length of the list: " << count << std::endl;
}


/*
 * Syntax: readData(integer, pointer of type node)
 * Return Value: void
 * Functionality: prints the value in a specific location.
 */
void linkedList::readData(int position, node* startPos)
{
    int count = 0;

    while(count != position)
    {
        startPos = (*startPos).nexPos;
        count++;
    }
    std::cout << (*startPos).data << std::endl;
}


/*
 * Syntax: modData(integer, integer, pointer of type node)
 * Return Value: void
 * Functionality: replaces the sent position with the sent new data.
 */
void linkedList::modData(int position, int new_data, node* startPos)
{
    int count = 0;

    while(count != position)
    {
        startPos = (*startPos).nexPos;
        count++;
    }
    (*startPos).data = new_data;
}


/*
 * Syntax: printLst(pointer of type node)
 * Return Value: void
 * Functionality: prints all the values in the linked list.
 */
void linkedList::printLst(node* starting_point)
{
    std::cout << "The entire list is:\n";

    std::cout << "[ ";

    while(starting_point != NULL)
    {
        std::cout << (*starting_point).data << "  ";
        starting_point = (*starting_point).nexPos;

    } 
    std::cout << "]\n";
}


/*
 * Syntax: removeAll(pointer of type node)
 * Return Value: void
 * Functionality: frees all the allocated memory in the linked list
 */
void linkedList::removeAll(node* starting_point)
{
    node* temp = NULL;

    while(starting_point != NULL)
    {
        temp = starting_point;
        std::cout << (*starting_point).data << " getting freed......" << std::endl;
        starting_point = (*starting_point).nexPos;
        free(temp);
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







