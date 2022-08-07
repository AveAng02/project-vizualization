#pragma once

#include <iostream>
#include <queue>


class BST {

public:

    struct node {
        int data;
        node* leftChild;
        node* rightChild;
    };

    node* hook = NULL;

    node* createNewNode(int data);

    node* insert(node* hook, int data);

    node* search(node* hook, int data);

    int Minimum(node* hook);

    node* minimum(node* hook);

    int maximum(node* hook);

    int height(node* hook);

    //Breadth first traversal is level order traversal
    void BFT(node* hook);

    /*
     * Depth first search is of three types:
     ** preorder <root><left><right>
     ** inorder <left><root><right>
     ** postorder <left><right><root>
     */

    void DFT_preorder(node* hook);

    void DFT_inorder(node* hook);

    void DFT_postorder(node* hook);

    /////////////////////////////////////

    bool isBST(node* hook);

    node* deleteNode(node* hook, int data); 

};




