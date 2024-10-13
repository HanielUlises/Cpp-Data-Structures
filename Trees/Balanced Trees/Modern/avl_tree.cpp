#include "avl_tree.h"
#include <algorithm>  // for std::max

// Constructor for avl_node
avl_node::avl_node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}

// Constructor for avl_tree
avl_tree::avl_tree() : root(nullptr) {}

// Get the height of the node
int avl_tree::get_height(const std::unique_ptr<avl_node>& node) const {
    return node ? node->height : 0;
}

// Get the balance factor of the node
int avl_tree::get_balance(const std::unique_ptr<avl_node>& node) const {
    return node ? get_height(node->left) - get_height(node->right) : 0;
}

// Perform a right rotation
std::unique_ptr<avl_node> avl_tree::right_rotate(std::unique_ptr<avl_node> y) {
    std::unique_ptr<avl_node> x = std::move(y->left);
    y->left = std::move(x->right);
    x->right = std::move(y);

    // Update heights
    x->right->height = std::max(get_height(x->right->left), get_height(x->right->right)) + 1;
    x->height = std::max(get_height(x->left), get_height(x->right)) + 1;

    return x;
}

// Perform a left rotation
std::unique_ptr<avl_node> avl_tree::left_rotate(std::unique_ptr<avl_node> x) {
    std::unique_ptr<avl_node> y = std::move(x->right);
    x->right = std::move(y->left);
    y->left = std::move(x);

    // Update heights
    y->left->height = std::max(get_height(y->left->left), get_height(y->left->right)) + 1;
    y->height = std::max(get_height(y->left), get_height(y->right)) + 1;

    return y;
}

// Insert a node with a given key
std::unique_ptr<avl_node> avl_tree::insert_node(std::unique_ptr<avl_node> node, int key) {
    if (!node) {
        return std::make_unique<avl_node>(key);
    }

    if (key < node->key) {
        node->left = insert_node(std::move(node->left), key);
    } else if (key > node->key) {
        node->right = insert_node(std::move(node->right), key);
    } else {
        return node; // Duplicate keys are not allowed
    }

    // Update the height of this node
    node->height = 1 + std::max(get_height(node->left), get_height(node->right));

    // Check the balance factor
    int balance = get_balance(node);

    // Perform rotations if necessary

    // Left Left Case
    if (balance > 1 && key < node->left->key) {
        return right_rotate(std::move(node));
    }

    // Right Right Case
    if (balance < -1 && key > node->right->key) {
        return left_rotate(std::move(node));
    }

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = left_rotate(std::move(node->left));
        return right_rotate(std::move(node));
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = right_rotate(std::move(node->right));
        return left_rotate(std::move(node));
    }

    return node;
}

// Insert a key into the AVL tree
void avl_tree::insert(int key) {
    root = insert_node(std::move(root), key);
}

// Find the node with the minimum value
avl_node* avl_tree::min_value_node(avl_node* node) const {
    avl_node* current = node;
    while (current->left != nullptr) {
        current = current->left.get();
    }
    return current;
}

// Remove a node with a given key
std::unique_ptr<avl_node> avl_tree::remove_node(std::unique_ptr<avl_node> node, int key) {
    if (!node) {
        return node;
    }

    if (key < node->key) {
        node->left = remove_node(std::move(node->left), key);
    } else if (key > node->key) {
        node->right = remove_node(std::move(node->right), key);
    } else {
        // Node with only one child or no child
        if (!node->left) {
            return std::move(node->right);
        } else if (!node->right) {
            return std::move(node->left);
        }

        // Node with two children: Get the in-order successor (smallest in the right subtree)
        avl_node* temp = min_value_node(node->right.get());
        node->key = temp->key;
        node->right = remove_node(std::move(node->right), temp->key);
    }

    if (!node) {
        return node;
    }

    // We then update height of the current node
    node->height = 1 + std::max(get_height(node->left), get_height(node->right));

    // Get the balance factor of this node
    int balance = get_balance(node);

    // Perform rotations if necessary

    // Left Left Case
    if (balance > 1 && get_balance(node->left) >= 0) {
        return right_rotate(std::move(node));
    }

    // Left Right Case
    if (balance > 1 && get_balance(node->left) < 0) {
        node->left = left_rotate(std::move(node->left));
        return right_rotate(std::move(node));
    }

    // Right Right Case
    if (balance < -1 && get_balance(node->right) <= 0) {
        return left_rotate(std::move(node));
    }

    // Right Left Case
    if (balance < -1 && get_balance(node->right) > 0) {
        node->right = right_rotate(std::move(node->right));
        return left_rotate(std::move(node));
    }

    return node;
}

// Remove a key from the AVL tree
void avl_tree::remove(int key) {
    root = remove_node(std::move(root), key);
}

// In-order traversal to print the AVL tree
void avl_tree::print_inorder(const avl_node* node) const {
    if (!node) {
        return;
    }
    print_inorder(node->left.get());
    std::cout << node->key << " ";
    print_inorder(node->right.get());
}

// Print the tree in-order
void avl_tree::print_inorder() const {
    print_inorder(root.get());
    std::cout << std::endl;
}
