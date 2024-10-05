#include <iostream>
#include "b_tree.h"

BTreeNode::BTreeNode(bool isLeaf, int degree) {
    this->isLeaf = isLeaf;
    this->degree = degree;
    keys = new int[2 * degree - 1];
    children = new BTreeNode*[2 * degree];
    numKeys = 0;
}

// Traversal
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < numKeys; i++) {
        if (!isLeaf)
            children[i]->traverse();
        std::cout << " " << keys[i];
    }
    if (!isLeaf)
        children[i]->traverse();
}

// Search a key in the subtree rooted with this node
BTreeNode* BTreeNode::search(int key) {
    int i = 0;
    while (i < numKeys && key > keys[i])
        i++;

    if (keys[i] == key)
        return this;

    if (isLeaf)
        return nullptr;

    return children[i]->search(key);
}

// Insert a key into a node that is not full
void BTreeNode::insertNonFull(int key) {
    int i = numKeys - 1;

    if (isLeaf) {
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
        numKeys += 1;
    }
    else {
        while (i >= 0 && keys[i] > key)
            i--;

        if (children[i + 1]->numKeys == 2 * degree - 1) {
            splitChild(i + 1, children[i + 1]);

            if (keys[i + 1] < key)
                i++;
        }
        children[i + 1]->insertNonFull(key);
    }
}

// Split the child node of this node
void BTreeNode::splitChild(int i, BTreeNode *y) {
    BTreeNode *z = new BTreeNode(y->isLeaf, degree);
    z->numKeys = degree - 1;

    for (int j = 0; j < degree - 1; j++)
        z->keys[j] = y->keys[j + degree];

    if (!y->isLeaf) {
        for (int j = 0; j < degree; j++)
            z->children[j] = y->children[j + degree];
    }

    y->numKeys = degree - 1;

    for (int j = numKeys; j >= i + 1; j--)
        children[j + 1] = children[j];

    children[i + 1] = z;

    for (int j = numKeys - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[degree - 1];
    numKeys += 1;
}

BTree::BTree(int degree) {
    root = nullptr;
    this->degree = degree;
}

BTree::~BTree() {
}

// Traverse 
void BTree::traverse() {
    if (root != nullptr)
        root->traverse();
}

// Search for a key in the B-tree
BTreeNode* BTree::search(int key) {
    return (root == nullptr) ? nullptr : root->search(key);
}

// Insert a new key in the B-tree
void BTree::insert(int key) {
    if (root == nullptr) {
        root = new BTreeNode(true, degree);
        root->keys[0] = key;
        root->numKeys = 1;
    }
    else {
        if (root->numKeys == 2 * degree - 1) {
            BTreeNode *newRoot = new BTreeNode(false, degree);
            newRoot->children[0] = root;
            newRoot->splitChild(0, root);

            int i = 0;
            if (newRoot->keys[0] < key)
                i++;
            newRoot->children[i]->insertNonFull(key);

            root = newRoot;
        }
        else
            root->insertNonFull(key);
    }
}