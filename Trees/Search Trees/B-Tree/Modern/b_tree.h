#ifndef BTREE_H
#define BTREE_H

#include <vector>
#include <memory>

// Forward declaration for BTree
class BTree;

// B-tree node class
class BTreeNode {
    std::vector<int> keys;                  // Vector of keys
    int degree;                             // Minimum degree (defines range for number of keys)
    std::vector<std::unique_ptr<BTreeNode>> children;  // Vector of child nodes
    int numKeys;                            // Current number of keys
    bool isLeaf;                            // Flag

public:
    BTreeNode(bool isLeaf, int degree);

    // Traverse the node
    void traverse() const;

    // Search for a key in this node
    BTreeNode* search(int key);

    // Insert a key into a non-full node
    void insertNonFull(int key);

    // Split the child node of this node
    void splitChild(int i, std::unique_ptr<BTreeNode>& y);

    friend class BTree;
};

// B-tree class
class BTree {
    std::unique_ptr<BTreeNode> root;  // Root node
    int degree;                       // Minimum degree

public:
    BTree(int degree);
    ~BTree() = default;

    // Traverse the entire tree
    void traverse() const;

    // Search for a key in the tree
    BTreeNode* search(int key);

    // Insert a new key into the tree
    void insert(int key);
};

#endif // BTREE_H
