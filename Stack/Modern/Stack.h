#pragma once

#include <memory>

template <class t_Data>
class Stack{
    struct Node{
        t_Data data;
        std::unique_ptr<Node> nextNode;
        
        // Node initializer
        Node (const t_Data &data) : data(t_Data) {}
    };

    std::unique_ptr<Node> head;
    int size = 0;

    public:
    // Proper methods of stack
    // Push a new element
    void push (const t_Data &newData){
        // First node to be inserted
        if (!head){
            head = std::make_unique<Node> (newData);
        }else{
            // UPDATE THE REFERENCES
            std::unique_ptr<Node> old_head = std::move(head);
            head = std::make_unique<Node> (newData);
            head -> nextNode = std::move(old_head);
        }

        size++;

    }

    // Pop the element from top
    t_Data pop (){
        if(isEmpty()){
            throw std::out_of_range("Stack has no elements.\n");
        }
        // Remove head node and update the references
        t_Data top_item = head -> data;
        std::unique_ptr<Node> temp = std::move(head -> nextNode);
        head = std::move(temp);

        size--;

        return top_item;
    }

    bool isEmpty (){
        return !head;
    }

    int size (){
        return size;
    }
};