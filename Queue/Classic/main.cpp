#include "Queue.h"

#include <iostream>

int main (){
    Queue new_test_queue;
    new_test_queue.enqueue(1);
    new_test_queue.enqueue(2);
    new_test_queue.enqueue(3);
    new_test_queue.enqueue(4);

    std::cout << new_test_queue.dequeue() << std::endl;

    return 0;
}