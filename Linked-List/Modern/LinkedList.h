#pragma once

#include "List.h"

#include <iostream>
#include <memory>

template<class t_Data>
class LinkedList : public List <t_Data>{

    struct Node{
        t_Data newData;
        // Reference to the next node of the list
        // Node type as nodes are self-referent
        std::unique_ptr<Node> nextNode;

        // Initialization of node
        // Constructor
        // At this point i think im making comments pretty similar to a LLM
        Node (const t_Data &_data)
            :data(_data)
        {}
    };
    // Size count
    int size = 0;

    // Reference to the head node of the linked list
    std::unique_ptr<Node> head;

    public:
    LinkedList () = default;

    // Proper methods of a linked list
    // Insert data at beginning of a linked list
    void insert (const t_Data &data) override{
        insertDataBeginning(data);
        size++;
    }

    // Remove node from the front
    void remove (const t_Data &) override{
        // If nothing, halt
        if(!head){
            return;
        }

        // Case: The node is the head node
        if (head -> data == data){
            auto newHead = std::move(head->nextNode);
            head = std::move(newHead);
            size--;
            return;
        }

        if(!head->nextNode){
            std::cout<< data << " not found in list" << std::endl;
            return;
        }

        // Case: Desired node is an internal node
        Node *prev = head.get();
        node *next = head->nextNode.get();

        // Find the node we desire to remove    
        while (next -> data != data){
            prev = next;
            next = next -> nextNode.get();
        }

        // Node was not found within the list
        if (!next){
            std::cout<< data << " not found in list" << std::endl;
            return;
        }

        // Update references
        std::unique_ptr<Node> temp = std::move(next -> nextNode);
        prev -> nextNode = std::move(temp);
    }

    void traverseList () const override{}
        // Starting with head
        Node  *node = head.get();
        // Print out all the nodes
        while (node){
            std::cout << node -> data << " ";
            // Next node (pretty clever)
            node = node -> nextNode.get();
        }
        std::cout<<std::endl;
    }

    int size () const override {
        return size;
    }

    private:
    void insertDataBeginning(const t_Data &data){
        std::unique_ptr<Node> newNode = std::make_unique<Node>(data);
        newNode -> nextNode = std::move(head);
        head = std::move(newNode);
    }
};  