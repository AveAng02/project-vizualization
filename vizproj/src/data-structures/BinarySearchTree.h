#pragma once

#include <iostream>
#include <queue>


class BinarySearchTree {

public:

    struct node {
        int data;
        node* leftChild;
        node* rightChild;
    };

    

    node* insert(int data);

    node* search(int data);

    int Minimum();

    node* minimum();

    int maximum();

    int height();

    //Breadth first traversal is level order traversal
    void BFT();

    /*
     * Depth first search is of three types:
     ** preorder <root><left><right>
     ** inorder <left><root><right>
     ** postorder <left><right><root>
     */

    void DFT_preorder();

    void DFT_inorder();

    void DFT_postorder();

    /////////////////////////////////////

    bool isBinarySearchTree();

    node* deleteNode(int data); 


private:

    node* root = nullptr;

    node* createNewNode(int data);

};




