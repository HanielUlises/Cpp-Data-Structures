#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <cstddef>

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    Node(const T& data);
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    std::size_t size;

public:
    DoublyLinkedList();

    ~DoublyLinkedList();

    void append(const T& data);

    void prepend(const T& data);

    void remove(Node<T>* node);

    void clear();

    std::size_t getSize() const;

    void printForward() const;
    void printBackward() const;
};

#include "DLL.cpp" 
#endif
