#pragma once

class Stack {
    struct Node {
        int data;
        Node* nextNode; 
        
        // Node initializer
        Node(const int& data) : data(data), nextNode(nullptr) {}
    };

    Node* head; 
    int size = 0;

public:
    // Proper methods of stack
    // Push a new element
    void push(const int& newData) {
        if (!head) {
            head = new Node(newData);
        } else {
            // UPDATE THE REFERENCES
            Node* old_head = head;
            head = new Node(newData);
            head->nextNode = old_head;
        }

        size++;
    }

    int pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack has no elements.\n");
        }

        int top_item = head->data;
        Node* temp = head->nextNode; 
        delete head; 
        head = temp;

        size--;

        return top_item;
    }

    bool isEmpty() {
        return !head;
    }

    int getSize() {
        return size;
    }

    ~Stack() {
        while (head) {
            Node* temp = head->nextNode;
            delete head;
            head = temp;
        }
    }
};
