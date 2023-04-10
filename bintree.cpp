/*********************
 * Evan Cazares
 * coding08
 * binary search tree skewed left
**********************/

#include "bintree.h"
BinTree::BinTree(){
    count = 0;
    root = NULL;
}

BinTree::~BinTree(){
    clear();
}

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

void BinTree::clear(){
    clear(root);
    count = 0;
}

void BinTree::clear(DataNode* curRoot){
    root = NULL;
    if(curRoot != NULL){
        clear(curRoot->left);
        clear(curRoot->right);
        curRoot->left = NULL;
        curRoot->right = NULL;
        delete curRoot; 
    }
    root = NULL;
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
        if(count < tempcount){
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
            if(curRoot->left == NULL){
                temp = curRoot->right; // save the right child and replace curRoot with temp
                curRoot = temp;
                delete curRoot; // becomes null pointer does not delete struct obj i think
                count--;
            } else if(curRoot->right == NULL){
                temp = curRoot->left;
                curRoot = temp;
                delete curRoot;
                count--;
            } else { // root with two children
                temp = findSucessor(curRoot->right);
                curRoot->data.id = temp->data.id;
                curRoot->data.information = temp->data.information;
                curRoot->right = removeNode(temp->data.id, curRoot->right);
                count--;
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
    return getHeight(root);
}

int BinTree::getHeight(DataNode* curRoot){ // needs to count everytime you backtrack
    int lh = 0, rh = 0;
    int num;
    if(curRoot != NULL){
        lh = getHeight(curRoot->left);
        rh = getHeight(curRoot->right);
        num = (rh + lh) + 1;
    } else {
        num = 0;
    }
    return num;
}

void BinTree::displayTree(){
    std::cout << "Pre-Order Traversal" << std::endl;
    displayPreOrder();
    std::cout << std::endl;
    std::cout << "In-Order Traversal" << std::endl;
    displayInOrder();
    std::cout << std::endl;
    std::cout << "Post-Order Traversal" << std::endl;
    displayPostOrder();
    std::cout << std::endl;
}

void BinTree::displayInOrder(){
    displayInOrder(root);
}

void BinTree::displayPostOrder(){
    displayPostOrder(root);
}

void BinTree::displayPreOrder(){
    displayPreOrder(root);
}

void BinTree::displayInOrder(DataNode* curRoot){
    if(curRoot != NULL){
        displayInOrder(curRoot->left);
        std::cout << curRoot->data.id << " " << curRoot->data.information << std::endl;
        displayInOrder(curRoot->right);
    }
}

void BinTree::displayPostOrder(DataNode* curRoot){
    if(curRoot != NULL){
        displayPreOrder(curRoot->left);
        displayPreOrder(curRoot->right);
        std::cout << curRoot->data.id << " " << curRoot->data.information << std::endl;
    }
}

void BinTree::displayPreOrder(DataNode* curRoot){
    if(curRoot != NULL){
        std::cout << curRoot->data.id << " " << curRoot->data.information << std::endl;
        displayPreOrder(curRoot->left);
        displayPreOrder(curRoot->right);
    }
}