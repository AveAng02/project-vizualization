#include "LinkedList.h"


/*
Write functions for the following features:
 * insert one element to the list
 * remove one element from the list
 * count length of list
 * read specific cell
 * modify the value of specific cell
 * print entire list
 */

 /* print entire list
void LinkedList::printList() {



}*/



/*
 * insertOntop : adds a node to the top of the list
 */
void LinkedList::insertOntop(int new_data)
{
    node* temp = (node*)malloc(sizeof(node));
    (*temp).data = new_data;
    (*temp).nexPos = top;
    top = temp;
}


/*
 * remove() : removes a node from the top of the list
 * 
 * remove(int pos) : removes a node from the top of the list ( range of position is [1,object.length()] )
 * 
 * removeFromend() : removes a node from the end of the list
 */
void LinkedList::remove()
{
    if(top != NULL)
    {
        node* temp = top;
        top = top->nexPos;

        std::cout << temp->data << " getting freed......" << std::endl;
        free(temp);
    }
    else
    {
        std::cout << "No nodes to be removed......." << std::endl;
    }
}

void LinkedList::remove(int pos)
{
    if (pos <= length()) {

        node* temp = top;

        int count = 1;

        while (pos != count) {

            temp = temp->nexPos;
            count++;

        }



    }
    
    
    if (top != NULL)
    {
        node* temp = top;
        top = top->nexPos;

        std::cout << temp->data << " getting freed......" << std::endl;
        free(temp);
    }
    else
    {
        std::cout << "No nodes to be removed......." << std::endl;
    }
}

/*
 * length : returns the length of the list
 */
int LinkedList::length()
{
    node* temp = top;

    int count = 0;

    while(top != NULL)
    {
        count++;
        temp = temp->nexPos;
    } 

    return count;
}


/*
 * Syntax: readData(integer, pointer of type node)
 * Return Value: void
 * Functionality: prints the value in a specific location.
 */
void LinkedList::readData(int position, node* startPos)
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
void LinkedList::modData(int position, int new_data, node* startPos)
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
void LinkedList::printLst(node* starting_point)
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
void LinkedList::removeAll(node* starting_point)
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







