#include "binaryTree.h"

// pointer to pointer method is more effecient for binary tree
// create a tree and binary tree class 
// under a DSA library


BST::node* BST::createNewNode(int data){
    node* newNode = new node();
    (*newNode).data = data;
    (*newNode).leftChild = (*newNode).rightChild = NULL;
    return newNode;
}

BST::node* BST::insert(node* hook, int data){
    if(hook == NULL){
        hook = createNewNode(data);
    }
    else if(hook->data > data){
        hook->leftChild = insert(hook->leftChild, data);
    }
    else if(hook->data < data){
        hook->rightChild = insert(hook->rightChild, data);
    }
    else{
        std::cout << "ERROR!! in insert section!" << hook->data << data << std::endl;
    }
    return hook;
}

BST::node* BST::search(node* hook, int data){
    if(hook == NULL){
        return NULL;
    }
    else if((hook->leftChild)->data == data || (hook->rightChild)->data == data){
        return hook;
    }
    else if(hook->data > data){
        return search(hook->leftChild, data);
    }
    else if(hook->data < data){
        return search(hook->rightChild, data);
    }
    else{
        std::cout << "Error!! In search function!" << std::endl;
        return NULL;
    }
}

int BST::Minimum(node* hook){
    if(hook == NULL){
        return -1;
    }
    else if(hook->leftChild == NULL){
        return hook->data;
    }
    else{
        return Minimum(hook->leftChild);
    }
}

BST::node* BST::minimum(node* hook){
    if(hook == NULL){
        return hook;
    }
    else if(hook->leftChild == NULL){
        return hook;
    }
    else{
        return minimum(hook->leftChild);
    }
}

int BST::maximum(node* hook){
    if(hook == NULL){
        return -1;
    }
    else if(hook->rightChild == NULL){
        return hook->data;
    }
    else{
        return maximum(hook->rightChild);
    }
}

int BST::height(node* hook){
    if(hook == NULL){
        return -1;
    }
    else if(height(hook->leftChild) > height(hook->rightChild)){
        return height(hook->leftChild) + 1;
    }
    else{
        return height(hook->rightChild) + 1;
    }
}

//Breadth first traversal is level order traversal
void BST::BFT(node* hook){
    if(hook == NULL){
        return;
    }

    std::queue<node*> q;
    node* front = NULL;

    q.push(hook);

    while(!q.empty()){
        front = q.front();

        std::cout << front->data << std::endl;

        if(front->leftChild != NULL){
            q.push(front->leftChild);
        }
        if(front->rightChild != NULL){
            q.push(front->rightChild);
        }
        q.pop();
    }
}

/*
 * Depth first search is of three types:
 ** preorder <root><left><right>
 ** inorder <left><root><right>
 ** postorder <left><right><root>
 */

void BST::DFT_preorder(node* hook){
    if(hook == NULL){
        return;
    }
    
    std::cout << hook->data << std::endl;
    DFT_preorder(hook->leftChild);
    DFT_preorder(hook->rightChild);
}

void BST::DFT_inorder(node* hook){
    if(hook == NULL){
        return;
    }
    
    DFT_inorder(hook->leftChild);
    std::cout << hook->data << std::endl;
    DFT_inorder(hook->rightChild);
}

void BST::DFT_postorder(node* hook){
    if(hook == NULL){
        return;
    }
    
    DFT_postorder(hook->leftChild);
    DFT_postorder(hook->rightChild);
    std::cout << hook->data << std::endl;
}

/////////////////////////////////////

bool BST::isBST(node* hook){
    if(hook == NULL || hook->leftChild == NULL || hook->rightChild == NULL){
        return true;
    }

    if(isBST(hook->leftChild) == true && isBST(hook->rightChild) == true && maximum(hook->leftChild) <= hook->data && hook->data <= Minimum(hook->rightChild)){
        return true;
    }
    else{
        return false;
    }
}

BST::node* BST::deleteNode(node* hook, int data){
    // Add senario when data is not found
    
    node* result = hook;
    
    if(result == NULL){
        return hook;
    }
    else if(data > hook->data){
        hook->rightChild = deleteNode(hook->rightChild, data);
    }
    else if(data < hook->data){
        hook->leftChild = deleteNode(hook->leftChild, data);
    }
    else{ // when the node is found
        if(hook->leftChild == NULL && hook->rightChild == NULL){
            delete hook;
            return NULL;    
        }
        else if(hook->leftChild == NULL){
            hook = hook->rightChild;
            delete result;
        }
        else if(hook->rightChild == NULL){
            hook = hook->leftChild;
            delete result;
        }
        else{ // for when both sides have data
            result = minimum(hook->rightChild);
            hook->data = result->data;
            hook->rightChild = deleteNode(hook->rightChild, result->data);
        }
    }

    return hook;
}









