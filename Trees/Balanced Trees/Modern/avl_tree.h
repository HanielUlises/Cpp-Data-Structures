#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <memory>

// Node for AVL Tree
struct avl_node {
    int key;
    std::unique_ptr<avl_node> left;
    std::unique_ptr<avl_node> right;
    int height;

    avl_node(int k);
};

// AVL Tree class definition
class avl_tree {
public:
    avl_tree();
    ~avl_tree() = default;

    void insert(int key);
    void remove(int key);
    void print_inorder() const;

private:
    std::unique_ptr<avl_node> root;

    int get_height(const std::unique_ptr<avl_node>& node) const;
    int get_balance(const std::unique_ptr<avl_node>& node) const;
    std::unique_ptr<avl_node> right_rotate(std::unique_ptr<avl_node> y);
    std::unique_ptr<avl_node> left_rotate(std::unique_ptr<avl_node> x);
    std::unique_ptr<avl_node> insert_node(std::unique_ptr<avl_node> node, int key);
    std::unique_ptr<avl_node> remove_node(std::unique_ptr<avl_node> node, int key);
    avl_node* min_value_node(avl_node* node) const;
    void print_inorder(const avl_node* node) const;
};

#endif // AVL_TREE_H
