#ifndef B_TREE_H
#define B_TREE_H

// B-tree node class
class BTreeNode {
    int *keys;             // Array of keys
    int degree;            // Minimum degree (defines the range for number of keys)
    BTreeNode **children;  // Array of child pointers
    int numKeys;           // Current number of keys
    bool isLeaf;           // Flag

public:
    BTreeNode(bool isLeaf, int degree);
    void traverse();

    // Finds a key in this node
    BTreeNode* search(int key);

    // Insert a key into the subtree rooted with this node
    void insertNonFull(int key);

    // Split the child node of this node
    void splitChild(int i, BTreeNode *y);

    friend class BTree;
};

// B-tree class
class BTree {
    BTreeNode *root;   // Root node
    int degree;        // Minimum degree

public:
    BTree(int degree);
    ~BTree();

    // Traverse the tree
    void traverse();

    // Search for a key
    BTreeNode* search(int key);

    // Insert a new key
    void insert(int key);
};

#endif // B_TREE_H
