#include "linkedList.h"

LinkedList::LinkedList(int value){
    Node *newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
}

LinkedList::~LinkedList(){
    Node *temp = head;
    while(head != nullptr){
        head = head->next;
        delete temp;
    }
}

void LinkedList::append(int value){
    Node *newNode = new Node(value);
    if(length == 0){
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

void LinkedList::prepend(int value){
    Node *newNode = new Node(value);
    if(length == 0){
        head = newNode;
        tail = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
    length++;
}

bool LinkedList::insert(int index, int value){
    if (index < 0 || index > length){
        return false;
    }else if (index  == 0){
        prepend(value);
        return true;
    }else if (index == length){
        append(value);
        return true;
    }

    Node *newNode = new Node(value);
    Node *temp = getNode (index - 1);

    newNode->next = temp->next;
    temp->next = newNode;

    length++;
    return true;
}
// Miscelanean functions
void LinkedList::printList(){
    Node *temp = head;
    while(temp != nullptr){
        std::cout<< temp->item<<std::endl;
        temp = temp->next;
    }
}

void LinkedList::reverseList(){
    Node *temp = head;
    head = tail;
    tail = temp;

    Node *after = temp->next;
    Node *before = nullptr;

    for(int i = 0; i < length; i++){
        after = temp->next;
        temp->next = before;
        before = temp;
        temp = after;
    }
}
// Deleters 
void LinkedList::deleteFirst(){
    if (head == nullptr) return;

    Node *temp = head;
    if(length == 1){
        head = nullptr;
        tail = nullptr;
    }else{
        head = head->next;
    }
    delete temp;
    length--;
}

void LinkedList::deleteLast(){
    if(length == 0) return;

    Node *temp = head;
    if(length == 1){
        head = nullptr;
        tail = nullptr;
    }else{
        Node *prev = head;;
        while(temp->next != nullptr){
            prev = temp;
            temp = temp->next;
        }
        tail = prev;
        tail->next = nullptr;
    }
    
    length--;
    delete temp;
}

void LinkedList::deleteNode(int index){
    if (index < 0 || index >= length){
        return;
    }else if (index == 0){
        return deleteFirst();
    }else if (index == length - 1){
        return deleteLast();
    }

    Node *prev = getNode(index - 1);
    Node *temp = prev->next;

    prev->next = temp->next;
    delete temp;
    length--;
}

// Getters and setters
void LinkedList::getHead(){
    std::cout<<head->item<<std::endl;
}

void LinkedList::getTail(){
    std::cout<<tail->item<<std::endl;
}

void LinkedList::getLength(){
    std::cout<<length<<std::endl;
}

Node* LinkedList::getNode (int index){
    if (index < 0 || index >= length) return nullptr;
    Node *temp = head;
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp;
}

bool LinkedList::setNode(int index, int value){
    Node *temp = getNode(index);
    if(temp != nullptr){
        temp->item = value;
        return true;
    }
    return false;
}