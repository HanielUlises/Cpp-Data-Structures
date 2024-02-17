#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef> 
#include <memory>
#include <utility>

template<typename T, typename Allocator = std::allocator<T>>
class Queue {
public:
    Queue() = default;
    ~Queue();

    Queue(const Queue& other);
    Queue& operator=(const Queue& other);

    Queue(Queue&& other) noexcept;
    Queue& operator=(Queue&& other) noexcept;

    bool empty() const noexcept;
    std::size_t size() const noexcept;

    void enqueue(const T& value);
    void enqueue(T&& value);

    T dequeue();

    const T& front() const;
    T& front();

private:
    struct Node {
        T data;
        Node* next = nullptr;

        template<typename... Args>
        Node(Args&&... args) : data(std::forward<Args>(args)...) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    std::size_t count = 0;

    Allocator alloc;
    using AllocTraits = std::allocator_traits<Allocator>;
    using NodeAllocator = typename AllocTraits::template rebind_alloc<Node>;
    NodeAllocator nodeAlloc;

    void clear();
    Node* createNode(const T& value);
    Node* createNode(T&& value);
};

template<typename T, typename Allocator>
Queue<T, Allocator>::~Queue() {
    clear();
}

template<typename T, typename Allocator>
bool Queue<T, Allocator>::empty() const noexcept {
    return head == nullptr;
}

template<typename T, typename Allocator>
std::size_t Queue<T, Allocator>::size() const noexcept {
    return count;
}

template<typename T, typename Allocator>
void Queue<T, Allocator>::enqueue(const T& value) {
    Node* newNode = createNode(value);
    if (tail) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
    ++count;
}

template<typename T, typename Allocator>
void Queue<T, Allocator>::enqueue(T&& value) {
    Node* newNode = createNode(std::move(value));
    if (tail) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
    ++count;
}

// Other member function implementations would go here...

#endif // QUEUE_H
