#include "Stack.h"

#include <iostream>

void main (){
    Stack<int> test_stack;
    
    test_stack.push(1);
    test_stack.push(2);
    test_stack.push(3);

    std::cout << test_stack.pop() << " popped from stack";
}
