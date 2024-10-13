#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <vector>
#include <limits>
#include <cstdlib>
#include <string>

template<typename K, typename V>
class SkipList {
private:
    struct Node {
        K key;
        V value;
        std::vector<Node*> forward;
        Node(K k, V v, int level) : key(k), value(v), forward(level + 1, nullptr) {}
    };

    Node* head;
    int maxLevel;
    float probability;
    int level;

    int randomLevel();

public:
    SkipList(int maxLevel = 16, float probability = 0.5);
    ~SkipList();
    void insert(K key, V value);
    bool remove(K key);
    bool search(K key, V &value);
};

#endif // SKIPLIST_H
