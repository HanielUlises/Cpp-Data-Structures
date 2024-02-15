#pragma once
#include <iostream>

class Queue {
private:
    static const int capacity = 100;
    int arr[capacity];
    int front;
    int rear;
    int count;

public:
    Queue() : front(0), rear(-1), count(0) {} // Constructor

    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1; // Using -1 to indicate the queue is empty, adjust as needed
        }
        int item = arr[front];
        front = (front + 1) % capacity;
        count--;
        return item;
    }

    int peek() const {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1; // Using -1 to indicate the queue is empty, adjust as needed
        }
        return arr[front];
    }

    int size() const {
        return count;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }
};
