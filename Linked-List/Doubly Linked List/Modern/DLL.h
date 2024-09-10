#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <memory>  
#include <cstddef>  

template <typename T>
struct Node {
    T data;
    std::unique_ptr<Node<T>> next;
    Node<T>* prev;

    explicit Node(const T& data);
};

template <typename T>
class DoublyLinkedList {
private:
    std::unique_ptr<Node<T>> head;
    Node<T>* tail;
    std::size_t size;

    Node<T>* getNodeAt(std::size_t index) const;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void append(const T& data);
    void prepend(const T& data);
    void insert_at(const T& data, std::size_t index);
    void remove(Node<T>* node);
    void clear();

    std::size_t getSize() const;

    void print_forward() const;
    void print_backward() const;
};

#include "DLL.cpp" // Include the implementation

#endif // DOUBLY_LINKED_LIST_H
