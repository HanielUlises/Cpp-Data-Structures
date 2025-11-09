#include "DLL.h"
#include <iostream>
#include <stdexcept>

template <typename T>
Node<T>::Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template <typename T>
void DoublyLinkedList<T>::append(const T& data) {
    auto newNode = std::make_unique<Node<T>>(data);
    Node<T>* newNodePtr = newNode.get(); 
    if (tail) {
        tail->next = std::move(newNode);
        newNodePtr->prev = tail;
        tail = newNodePtr;
    } else {
        head = std::move(newNode);
        tail = head.get();
    }
    ++size;
}

template <typename T>
void DoublyLinkedList<T>::prepend(const T& data) {
    auto newNode = std::make_unique<Node<T>>(data);
    Node<T>* newNodePtr = newNode.get();  

    if (head) {
        newNode->next = std::move(head);
        newNode->next->prev = newNodePtr;
        head = std::move(newNode);
    } else {
        head = std::move(newNode);
        tail = head.get();
    }
    ++size;
}

template <typename T>
void DoublyLinkedList<T>::insert_at(const T& data, std::size_t index) {
    if (index > size) {
        throw std::out_of_range("Index out of range");
    }

    if (index == 0) {
        prepend(data);
    } else if (index == size) {
        append(data);
    } else {
        auto newNode = std::make_unique<Node<T>>(data);
        Node<T>* newNodePtr = newNode.get(); 

        Node<T>* prevNode = getNodeAt(index - 1);
        Node<T>* nextNode = prevNode->next.get();

        newNode->next = std::move(prevNode->next);
        if (newNode->next) newNode->next->prev = newNodePtr;

        prevNode->next = std::move(newNode);
        prevNode->next->prev = prevNode;

        ++size;
    }
}

template <typename T>
void DoublyLinkedList<T>::remove(Node<T>* node) {
    if (!node) return;

    if (node->prev) node->prev->next = std::move(node->next);
    else head = std::move(node->next);

    if (node->next) node->next->prev = node->prev;
    else tail = node->prev;

    --size;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    while (head) {
        head = std::move(head->next);
    }
    tail = nullptr;
    size = 0;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::getNodeAt(std::size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }

    Node<T>* current = head.get();
    for (std::size_t i = 0; i < index; ++i) {
        current = current->next.get();
    }
    return current;
}

template <typename T>
std::size_t DoublyLinkedList<T>::getSize() const {
    return size;
}

template <typename T>
void DoublyLinkedList<T>::print_forward() const {
    Node<T>* current = head.get();
    while (current) {
        std::cout << current->data << " ";
        current = current->next.get();
    }
    std::cout << std::endl;
}

template <typename T>
void DoublyLinkedList<T>::print_backward() const {
    Node<T>* current = tail;
    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}
