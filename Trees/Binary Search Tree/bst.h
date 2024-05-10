#ifndef BST_H
#define BST_H

#include <iostream>
#include <memory>

class BST {
public:
    // Node structure for BST
    struct Node {
        int key;        // Key of the node
        Node* left;     // Pointer to the left child
        Node* right;    // Pointer to the right child

        // Constructor to create a new node
        Node(int k) : key(k), left(nullptr), right(nullptr) {}
    };

    // Constructor and destructor
    BST();
    ~BST();

    // Inserts a key into the BST
    void insert(int key);

    // Removes a key from the BST
    void remove(int key);

    // Searches for a key in the BST
    bool search(int key) const;

    // Traverses the BST in-order
    void inorder_traversal() const;

    // Traverses the BST pre-order
    void preorder_traversal() const;

    // Traverses the BST post-order
    void postorder_traversal() const;

private:
    Node* root; // Root of the BST

    // Helper functions
    Node* insertUtil(Node* root, int key);
    Node* removeUtil(Node* root, int key);
    Node* findMin(Node* root) const;
    bool searchUtil(Node* root, int key) const;
    void inorderUtil(Node* root) const;
    void preorderUtil(Node* root) const;
    void postorderUtil(Node* root) const;
};

#endif // BST_H
