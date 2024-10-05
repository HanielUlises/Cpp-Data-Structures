#include <iostream>
#include "b_tree.h"


// Initializes a node, either as a leaf or an internal node
BTreeNode::BTreeNode(bool isLeaf, int degree)
    : isLeaf(isLeaf), degree(degree), numKeys(0) {
    keys.resize(2 * degree - 1);   // Maximum number of keys a node can hold
    children.resize(2 * degree);   // Maximum number of child pointers a node can have
}

// Traverse all nodes in a subtree rooted with this node
void BTreeNode::traverse() const {
    // Go through each key and traverse the subtree before printing the key (if not a leaf)
    for (int i = 0; i < numKeys; ++i) {
        if (!isLeaf) {
            // Recursively traverse the subtree of the child node before the current key
            children[i]->traverse();
        }
        std::cout << " " << keys[i]; 
    }

    // If the node is not a leaf, recursively traverse the subtree rooted at the last child
    if (!isLeaf) {
        children[numKeys]->traverse();
    }
    // Base case: If the node is a leaf (isLeaf == true), no recursive calls are made.
    // The traversal will simply print the keys in this leaf node and return.
}

// Search a key in the subtree rooted with this node
BTreeNode* BTreeNode::search(int key) {
    // Find the first key greater than or equal to key
    int i = 0;
    while (i < numKeys && key > keys[i]) {
        i++;
    }

    // Base case: If the key is found in this node, return this node
    if (i < numKeys && keys[i] == key) {
        return this;  // Base case: key is found
    }

    // If the node is a leaf, key is not present
    if (isLeaf) {
        return nullptr;  // Base case: Reached a leaf and key not found
    }

    // Recur to the appropriate child
    // Recursive case: move to the child
    return children[i]->search(key);  
}

// Insert a key into a non-full node
// Called when the node has space for a new key
void BTreeNode::insertNonFull(int key) {
    // Start: the rightmost key
    int i = numKeys - 1;  

    if (isLeaf) {
        // Base case: If the node is a leaf, find the correct position to insert the key
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];  // Shift keys to the right
            i--;
        }
        keys[i + 1] = key;  // Insert the new key
        numKeys++;  // Increment the number of keys
    } else {
        // Recursive case: The node is not a leaf, find the child that will receive the new key
        while (i >= 0 && keys[i] > key) {
            i--;
        }

        // Check if the child where the key needs to be inserted is full
        if (children[i + 1]->numKeys == 2 * degree - 1) {
            // If the child is full, split it
            splitChild(i + 1, children[i + 1]);

            // After splitting, determine which of the two children is going to receive the new key
            if (keys[i + 1] < key) {
                i++;
            }
        }
        // Recur to insert in the appropriate child
        children[i + 1]->insertNonFull(key);
    }
}

// Split the child node of this node
// `i` is the index of the child to split, `y` is the node to be split
void BTreeNode::splitChild(int i, std::unique_ptr<BTreeNode>& y) {
    // Create a new node that will store (degree-1) keys of y
    auto z = std::make_unique<BTreeNode>(y->isLeaf, degree);
    z->numKeys = degree - 1;

    // Copy the last (degree-1) keys of y to z
    for (int j = 0; j < degree - 1; ++j) {
        z->keys[j] = y->keys[j + degree];
    }

    // Copy the last (degree) children of y to z, if y is not a leaf
    if (!y->isLeaf) {
        for (int j = 0; j < degree; ++j) {
            z->children[j] = std::move(y->children[j + degree]);
        }
    }

    // Reduce the number of keys in y
    y->numKeys = degree - 1;

    // Shift children of the current node to make space for the new child
    for (int j = numKeys; j >= i + 1; --j) {
        children[j + 1] = std::move(children[j]);
    }

    // Link the new child to this node
    children[i + 1] = std::move(z);

    // Shift keys of the current node to make space for the middle key of y
    for (int j = numKeys - 1; j >= i; --j) {
        keys[j + 1] = keys[j];
    }

    // Copy the middle key of y to this node
    keys[i] = y->keys[degree - 1];
    numKeys++; 
}

BTree::BTree(int degree) : degree(degree) {
    root = nullptr;  
}

// Traverse the entire tree
void BTree::traverse() const {
    if (root) {
        // Traverse from the root if it exists
        root->traverse();  
    }
}

// Search for a key in the B-tree
BTreeNode* BTree::search(int key) {
    // If the tree is non-empty, we search from the root
    return root ? root->search(key) : nullptr;  
}

// Insert a new key in the B-tree
void BTree::insert(int key) {
    // If the tree is empty, create a new root
    if (!root) {
        root = std::make_unique<BTreeNode>(true, degree);  // The new root is a leaf
        root->keys[0] = key;  // Insert the first key
        root->numKeys = 1;  // Only one key in the root
    } else {
        // If the root is full, the tree grows in height
        if (root->numKeys == 2 * degree - 1) {
            auto newRoot = std::make_unique<BTreeNode>(false, degree);  // The new root is not a leaf
            newRoot->children[0] = std::move(root);  // The old root becomes the first child of the new root

            // Split the old root and move a key to the new root
            newRoot->splitChild(0, newRoot->children[0]);

            // Decide which child of the new root will have the new key
            int i = (newRoot->keys[0] < key) ? 1 : 0;
            newRoot->children[i]->insertNonFull(key);

            root = std::move(newRoot);  // Update the root
        } else {
            // If the root is not full, insert the key in the root
            root->insertNonFull(key);
        }
    }
}
