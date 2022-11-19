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
    bool sucess = false;
    if(root == NULL){
        temp->id = -1;
        temp->information = "";
    } else {
        temp->id = root->data.id;
        temp->information = root->data.information;
        sucess = true;  
    }
    return sucess;
}

// overloaded public methods
void BinTree::clear(){
    clear(root);
}

void BinTree::clear(DataNode* curRoot){
    count = 0;
    if(curRoot != NULL){
        clear(curRoot->left);
        clear(curRoot->right);
        curRoot->left = NULL;
        curRoot->right = NULL;
        delete curRoot;
    }
}

// private overloading methods
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
        if(sucess){
            count++;
        }
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

bool BinTree::removeNode(int id){
    // removes the node, needs cases for removing true root, other roots, and leafs
    int sucess = false;
    if(id>0){
        int tempcount = count;
        root = removeNode(id, root);
        if(count > tempcount){
            sucess = true;
        }
    }
    return sucess;
}

DataNode* BinTree::removeNode(int id, DataNode* curRoot){ 
    if(curRoot != NULL){
        if(id < curRoot->data.id){ // binary search until node is found or not found
            curRoot->left = removeNode(id, curRoot->left);
        } else if (id > curRoot->data.id){ // binary search until node is found or not found
            curRoot->right = removeNode(id, curRoot->right);
        } else { // if we find the id
            DataNode* temp = new DataNode; // create temp DataNode
            count--;
            if(curRoot->left == NULL){
                temp = curRoot->right; // save the right child and replace curRoot with temp
                curRoot = temp;
                delete curRoot; // becomes null pointer does not delete struct obj i think
            } else if(curRoot->right == NULL){
                temp = curRoot->left;
                curRoot = temp;
                delete curRoot;
            } else { // root with two children
                temp = findSucessor(curRoot->right);
                curRoot->data.id = temp->data.id;
                curRoot->data.information = temp->data.information;
                curRoot->right = removeNode(temp->data.id, curRoot->right);
            }
        }
        return curRoot;
    } else { // if curRoot is empty just return it making stopping criteria
        return curRoot;
    }
}

DataNode* BinTree::findSucessor(DataNode* node){
    DataNode* current = node;
    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
}

bool BinTree::getNode(Data* temp, int id){ // uses private method to call and access root
    // uses binary search to find the node and fills temp struct
    bool sucess = false;
    if(id>0){
        sucess = getNode(temp, id, root);
    }
    return sucess;
}

bool BinTree::getNode(Data* temp, int id, DataNode* curRoot){
    bool sucess = false;
    if(curRoot == NULL){
        sucess = false;
    } else { // if root not empty
        if(id == curRoot->data.id){
            sucess = true;
            temp->id = curRoot->data.id;
            temp->information = curRoot->data.information;
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

int BinTree::getHeight(){
    // calclates hieght each time its called
    bool sucess = false;
    sucess = getHeight(root);
    return sucess;
}

int BinTree::getHeight(DataNode* curRoot){
    int lh = 0, rh = 0;
    int num = 1;
    if(curRoot == NULL){
        num = 0;
    } else {
        lh = getHeight(curRoot->left);
        rh = getHeight(curRoot->right);
    }
    return (num * (lh + rh + 1));
}

void BinTree::displayTree(){
    // cannot do yet
}

void BinTree::displayInOrder(){

}

void BinTree::displayPostOrder(){

}

void BinTree::displayPreOrder(){

}

void BinTree::displayInOrder(DataNode* root){
    
}

void BinTree::displayPostOrder(DataNode* root){

}

void BinTree::displayPreOrder(DataNode* root){

}