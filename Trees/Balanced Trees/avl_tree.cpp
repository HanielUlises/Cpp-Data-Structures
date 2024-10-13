#include "avl_tree.h"

avl_tree::avl_tree() {
    root = nullptr;
}

avl_tree::~avl_tree() {
    delete_tree(root);
}

int avl_tree::get_height(avl_node* node) {
    return node ? node->height : 0;
}

int avl_tree::get_balance(avl_node* node) {
    return node ? get_height(node->left) - get_height(node->right) : 0;
}

// Right rotation to balance the tree
avl_node* avl_tree::right_rotate(avl_node* y) {
    avl_node* x = y->left;
    avl_node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(get_height(y->left), get_height(y->right)) + 1;
    x->height = std::max(get_height(x->left), get_height(x->right)) + 1;
    // New root
    return x;  
}

// Left rotation to balance the tree
avl_node* avl_tree::left_rotate(avl_node* x) {
    avl_node* y = x->right;
    avl_node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(get_height(x->left), get_height(x->right)) + 1;
    y->height = std::max(get_height(y->left), get_height(y->right)) + 1;
    // New root
    return y;  
}

// Insert function (public)
void avl_tree::insert(int key) {
    root = insert_node(root, key);
}

// Insert function (private)
avl_node* avl_tree::insert_node(avl_node* node, int key) {
    if (!node) return new avl_node(key);

    if (key < node->key)
        node->left = insert_node(node->left, key);
    else if (key > node->key)
        node->right = insert_node(node->right, key);
    else
    // Duplicate keys ae not allowed
        return node;  

    // Update height
    node->height = 1 + std::max(get_height(node->left), get_height(node->right));

    // Get balance factor
    int balance = get_balance(node);

    // Perform rotations if necessary
    if (balance > 1 && key < node->left->key)
        return right_rotate(node);

    if (balance < -1 && key > node->right->key)
        return left_rotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    // Unchanged node pointer
    return node;  
}

// Remove function (public)
void avl_tree::remove(int key) {
    root = remove_node(root, key);
}

// Remove function (private)
avl_node* avl_tree::remove_node(avl_node* node, int key) {
    if (!node) return node;

    if (key < node->key)
        node->left = remove_node(node->left, key);
    else if (key > node->key)
        node->right = remove_node(node->right, key);
    else {
        if (!node->left || !node->right) {
            avl_node* temp = node->left ? node->left : node->right;

            if (!temp) {
                temp = node;
                node = nullptr;
            } else
                *node = *temp;

            delete temp;
        } else {
            avl_node* temp = min_value_node(node->right);
            node->key = temp->key;
            node->right = remove_node(node->right, temp->key);
        }
    }

    if (!node) return node;

    node->height = 1 + std::max(get_height(node->left), get_height(node->right));

    int balance = get_balance(node);

    if (balance > 1 && get_balance(node->left) >= 0)
        return right_rotate(node);

    if (balance > 1 && get_balance(node->left) < 0) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    if (balance < -1 && get_balance(node->right) <= 0)
        return left_rotate(node);

    if (balance < -1 && get_balance(node->right) > 0) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

// Find the node with minimum key value
avl_node* avl_tree::min_value_node(avl_node* node) {
    avl_node* current = node;
    while (current->left)
        current = current->left;
    return current;
}

// Print the AVL tree in inorder traversal
void avl_tree::print_inorder() {
    print_inorder(root);
    std::cout << std::endl;
}

// Inorder traversal 
void avl_tree::print_inorder(avl_node* node) {
    if (!node) return;
    print_inorder(node->left);
    std::cout << node->key << " ";
    print_inorder(node->right);
}

void avl_tree::delete_tree(avl_node* node) {
    if (node) {
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }
}
