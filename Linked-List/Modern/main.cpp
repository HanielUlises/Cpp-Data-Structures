#include "LinkedList.h"

int main (){
    std::unique_ptr<List<int>> test_linked_list = std::make_unique<LinkedList<int>>();

    test_linked_list -> insert (1);
    test_linked_list -> insert (2);
    test_linked_list -> insert (3);
    test_linked_list -> insert (4);
    test_linked_list -> insert (5);

    test_linked_list -> traverseList();

    test_linked_list -> remove (1);
    test_linked_list -> traverseList();
}