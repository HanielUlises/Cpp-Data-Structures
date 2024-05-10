#include "BST.h"

BST::BST() : root(nullptr) {}

BST::~BST() {
    while (root != nullptr) {
        remove(root->key);
    }
}

// Function to insert a key
void BST::insert(int key) {
    root = insertUtil(root, key);
}

// Helper function for insertion
BST::Node* BST::insertUtil(Node* node, int key) {
    if (node == nullptr) {
        return new Node(key);
    }
    if (key < node->key) {
        node->left = insertUtil(node->left, key);
    } else if (key > node->key) {
        node->right = insertUtil(node->right, key);
    }
    return node;
}

// Function to remove a key
void BST::remove(int key) {
    root = removeUtil(root, key);
}

// Helper function for removal
BST::Node* BST::removeUtil(Node* node, int key) {
    if (node == nullptr) return node;

    if (key < node->key) {
        node->left = removeUtil(node->left, key);
    } else if (key > node->key) {
        node->right = removeUtil(node->right, key);
    } else {
        // Node with only one child or no child
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(node->right);

        // Then, one must copy the inorder successor's content to this current node
        node->key = temp->key;

        // Removing inorder successor
        node->right = removeUtil(node->right, temp->key);
    }
    return node;
}

// Function to find the minimum node (used in removeUtil)
BST::Node* BST::findMin(Node* node) const {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Function to search for a key
bool BST::search(int key) const {
    return searchUtil(root, key);
}

// Helper function for search in a BST
bool BST::searchUtil(Node* node, int key) const {
    if (node == nullptr) {
        return false;
    }
    if (key < node->key) {
        return searchUtil(node->left, key);
    } else if (key > node->key) {
        return searchUtil(node->right, key);
    } else {
         // Key was found
        return true;
    }
}

// In-order traversal
void BST::inorder_traversal() const {
    inorderUtil(root);
    std::cout << std::endl;
}

// Helper function for in-order traversal
void BST::inorderUtil(Node* node) const {
    if (node != nullptr) {
        inorderUtil(node->left);
        std::cout << node->key << " ";
        inorderUtil(node->right);
    }
}

//Pre-order traversal
void BST::preorder_traversal() const {
    preorderUtil(root);
    std::cout << std::endl;
}

// Helper function for pre-order traversal
void BST::preorderUtil(Node* node) const {
    if (node != nullptr) {
        std::cout << node->key << " ";
        preorderUtil(node->left);
        preorderUtil(node->right);
    }
}

// Post-order traversal
void BST::postorder_traversal() const {
    postorderUtil(root);
    std::cout << std::endl;
}

// Helper function for post-order traversal
void BST::postorderUtil(Node* node) const {
    if (node != nullptr) {
        postorderUtil(node->left);
        postorderUtil(node->right);
        std::cout << node->key << " ";
    }
}
