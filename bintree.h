/*********************
 * Evan Cazares
 * coding08
 * binary search tree skewed left
**********************/

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

// class definition
#include <iostream>
#include "data.h"

class BinTree{
    private:
    DataNode *root;
    int count;

    void clear(DataNode*);
    bool addNode(DataNode*, DataNode**);
    DataNode* removeNode(int, DataNode*);
    bool getNode(int, Data*, DataNode*);
    bool contains(int, DataNode*);
    int getHeight(DataNode*);
    void displayPreOrder(DataNode*);
    void displayPostOrder(DataNode*);
    void displayInOrder(DataNode*);

    public:
    BinTree();
    ~BinTree();
    bool isEmpty();
    int getCount();
    bool getRootData(Data*);
    void displayTree();

    void clear();
    bool addNode(int, const string*);
    bool removeNode(int);
    bool getNode(int, Data*);
    bool contains(int);
    int getHeight();
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();
};


#endif /* BINTREE_BINTREE_H */

