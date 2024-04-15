#include "queue.h"
#include <iostream>
#include <string>

int main() {
    Queue<int> intQueue;

    std::cout << "Enqueueing elements: 10, 20, 30\n";
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);

    std::cout << "Current size of queue: " << intQueue.size() << std::endl;

    std::cout << "Element at front: " << intQueue.front() << std::endl;

    std::cout << "Dequeuing elements\n";
    while (!intQueue.empty()) {
        std::cout << "Dequeued: " << intQueue.dequeue() << std::endl;
    }

    std::cout << "Current size of queue after dequeuing: " << intQueue.size() << std::endl;

    Queue<std::string> stringQueue;
    std::cout << "Enqueueing strings: Hello, World, Test\n";
    stringQueue.enqueue("Hello");
    stringQueue.enqueue("World");
    stringQueue.enqueue("Test");

    std::cout << "Dequeuing strings\n";
    while (!stringQueue.empty()) {
        std::cout << "Dequeued: " << stringQueue.dequeue() << std::endl;
    }

    return 0;
}
