#pragma once

#include "List.h"

#include <iostream>
#include <memory>

template<class t_Data>
class LinkedList : public List <t_Data>{

    struct Node{
        t_Data newData;

        std::unique_ptr<Node> next_node;

        Node (const t_Data &_data)
            :data(_data)
        {}
    };

    int size = 0;
    std::unique_ptr<Node> head;

    public:
    LinkedList () = default;

    // Proper methods of a linked list
    // Insert data at beginning of a linked list
    void insert (const t_Data &data) override{
        insert_data_beginning(data);
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
            auto newHead = std::move(head->next_node);
            head = std::move(newHead);
            size--;
            return;
        }

        if(!head -> next_node){
            std::cout<< data << " not found in list" << std::endl;
            return;
        }

        // Case: Desired node is an internal node
        Node *prev = head.get();
        node *next = head->next_node.get();

        // Find the node we desire to remove    
        while (next -> data != data){
            prev = next;
            next = next -> next_node.get();
        }

        // Node was not found within the list
        if (!next){
            std::cout<< data << " not found in list" << std::endl;
            return;
        }

        // Update references
        std::unique_ptr<Node> temp = std::move(next -> next_node);
        prev -> next_node = std::move(temp);
    }

    void traverse_list () const override{
        Node  *node = head.get();
        while (node){
            std::cout << node -> data << " ";
            node = node -> next_node.get();
        }
        std::cout<<std::endl;
    }

    int get_size () const override {
        return size;
    }

    private:
    void insert_data_beginning(const t_Data &data){
        std::unique_ptr<Node> newNode = std::make_unique<Node>(data);
        newNode -> next_node = std::move(head);
        head = std::move(newNode);
    }
};  