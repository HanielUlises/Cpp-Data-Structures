#include "DLL.h"
#include <iostream>

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
    Node<T>* newNode = new Node<T>(data);
    if (tail) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    } else {
        head = tail = newNode;
    }
    ++size;
}

template <typename T>
void DoublyLinkedList<T>::prepend(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    if (head) {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    } else {
        head = tail = newNode;
    }
    ++size;
}

template <typename T>
void DoublyLinkedList<T>::remove(Node<T>* node) {
    if (!node) return;

    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;
    if (node == head) head = node->next;
    if (node == tail) tail = node->prev;

    delete node;
    --size;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    Node<T>* current = head;
    while (current) {
        Node<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = tail = nullptr;
    size = 0;
}

template <typename T>
std::size_t DoublyLinkedList<T>::getSize() const {
    return size;
}

template <typename T>
void DoublyLinkedList<T>::printForward() const {
    Node<T>* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
void DoublyLinkedList<T>::printBackward() const {
    Node<T>* current = tail;
    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}
