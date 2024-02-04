#include "Stack.h"

#include <iostream>

int main (){
    Stack new_test_stack;
    new_test_stack.push(1);
    new_test_stack.push(2);
    new_test_stack.push(3);

    std::cout<< new_test_stack.pop() << " was popped from stack"<<std::endl;

    return 0;
}