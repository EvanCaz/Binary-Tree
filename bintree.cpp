/*********************
 * Evan Cazares
 * coding08
 * binary search tree skewed left
**********************/

#include "bintree.h"


// class init

BinTree::BinTree(){
    count = 0;
    root = NULL;
}
BinTree::~BinTree(){
    //destructor idk yet
}

// public methods

bool BinTree::isEmpty(){
    return root == NULL;
}

int BinTree::getCount(){
    return count;
}

bool BinTree::getRootData(Data* temp){
    // return data in the true root
    // uses current marker for familiarirty

    DataNode* current = root; // sets current to the root(head)
    bool sucess = false;
    if(current == NULL){
        temp->id = -1;
        temp->information = "";
    } else {
        temp->id = current->data.id;
        temp->information = current->data.information;
    }
    return sucess;
}

void BinTree::displayTree(){
    // cannot do yet
}

// overloaded public methods

void BinTree::clear(){
    // sets root to null and deallocates all memory
}


bool BinTree::removeNode(int id){
    // removes the node, needs cases for removing true root, other roots, and leafs
    return false;
}



int BinTree::getHeight(){
    // calclates hieght each time its called
    return 0;
}

void BinTree::displayInOrder(){

}

void BinTree::displayPostOrder(){

}

void BinTree::displayPreOrder(){

}

// private overloading methods

void BinTree::clear(DataNode* root){

}

bool BinTree::addNode(int id, const string* data){
    // creaets a node, finds location, inserts node
    bool sucess = false;
    if(id > 0 && *data != ""){ // validate data
        DataNode* newNode = new DataNode;
        newNode->data.id = id;
        newNode->data.information = *data;
        newNode->left = NULL;
        newNode->right = NULL; 
        sucess = addNode(newNode, &root); // pass adress of true root and address of new node
    }
    return sucess;
}

bool BinTree::addNode(DataNode* newNode, DataNode** curRoot){
    //called by puclic method and passed root and true root, recursion and binary search to find spot then add
    bool sucess = false;
    if(*curRoot != NULL){ // stopping criteria, if the current root does not equal null
        if(newNode->data.id < (*curRoot)->data.id){ // binary serach, if id is less then id at current spot, go left ignore all right
            sucess = addNode(newNode, &(*curRoot)->left);
        } else if (newNode->data.id > (*curRoot)->data.id){ // if id greater than current, ignore all left and go right
            sucess = addNode(newNode, &(*curRoot)->right);
        }
    } else { // if curRoot does equal null, add newNode with specifed case for left and right
        *curRoot = newNode;
        sucess = true;
    }
    return sucess;
}

DataNode* BinTree::removeNode(int id, DataNode* root){ // throws warning for no return statment

}

bool BinTree::getNode(Data* temp, int id, DataNode* curRoot){
    return false;
}

bool BinTree::getNode(Data* temp, int id){ // uses private method to call and access root
    // uses binary search to find the node and fills temp struct
    return false;
}

bool BinTree::contains(int id){
    bool sucess = false;
    if(id > 0){
        sucess = contains(id, root);
    }
    return sucess;
}

bool BinTree::contains(int id, DataNode* curRoot){
    bool sucess = false;
    if(curRoot == NULL){
        sucess = false;
    } else { // if root not empty
        if(id == curRoot->data.id){
            sucess = true;
        } else {
            if(id < curRoot->data.id){ // binary serach, if id is less then id at current spot, go left ignore all right
                sucess = contains(id, curRoot->left);
            } else if (id > curRoot->data.id){ // if id greater than current, ignore all left and go right
                sucess = contains(id, curRoot->right);
            }
        }
    }
    return sucess;
}

int BinTree::getHeight(DataNode* root){
    return 0;
}

void BinTree::displayInOrder(DataNode* root){

}

void BinTree::displayPostOrder(DataNode* root){

}

void BinTree::displayPreOrder(DataNode* root){

}