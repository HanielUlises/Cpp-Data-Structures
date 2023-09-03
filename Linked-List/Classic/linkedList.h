#pragma once

#include "iostream"
#include "cstdlib"

class LinkedList{
    public:
        // Create a new node
        LinkedList(int value);
        // Creates a new node and adds node to the end
        void append(int value);
        // Creates a new node and adds node to the beggining
        void prepend(int value);
        // Creates a new node and inserts it to an index
        bool insert(int index, int value);
        // Prints out the elements 
        void printList();
        // Deletes the first node
        void deleteFirst();
        // Deletes the last node
        void deleteLast();
        // Deletes an specific node
        void deleteNode(int index);
        // Sets a node at an specific index
        bool setNode (int index, int value);

        // I mean uhhhh
        void reverseList();

        // Getters
        void getHead();
        void getTail();
        void getLength();
        Node* getNode(int index);

        // DESTRUCTOR!!
        ~LinkedList();
    private:
        Node *head = nullptr;
        Node *tail = nullptr;
        int length = 0;
};

class Node{
    public:
        int item;
        Node *next;

        Node(int item){
            this->item = item;
            this->next = nullptr;
        }

};