#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>

// Node for AVL Tree
struct avl_node {
    int key;
    avl_node* left;
    avl_node* right;
    int height;

    avl_node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

// AVL Tree class definition
class avl_tree {
public:
    avl_tree();               
    ~avl_tree();            

    void insert(int key);      // insert node
    void remove(int key);      // Remove node
    void print_inorder();      // Print tree in inorder

private:
    avl_node* root;            // Root of the AVL tree

    int get_height(avl_node* node);
    int get_balance(avl_node* node);
    avl_node* right_rotate(avl_node* y);
    avl_node* left_rotate(avl_node* x);
    avl_node* insert_node(avl_node* node, int key);
    avl_node* remove_node(avl_node* node, int key);
    avl_node* min_value_node(avl_node* node);
    void print_inorder(avl_node* node);
    void delete_tree(avl_node* node);
};

#endif // AVL_TREE_H
