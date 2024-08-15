#include "SkipList.h"

template<typename K, typename V>
SkipList<K, V>::SkipList(int maxLevel, float probability) 
    : maxLevel(maxLevel), probability(probability), level(0) {
    head = new Node(K(), V(), maxLevel);
}

template<typename K, typename V>
SkipList<K, V>::~SkipList() {
    Node* current = head;
    while (current) {
        Node* next = current->forward[0];
        delete current;
        current = next;
    }
}

template<typename K, typename V>
int SkipList<K, V>::randomLevel() {
    int lvl = 0;
    while (static_cast<float>(rand()) / RAND_MAX < probability && lvl < maxLevel) {
        lvl++;
    }
    return lvl;
}

template<typename K, typename V>
void SkipList<K, V>::insert(K key, V value) {
    std::vector<Node*> update(maxLevel + 1);
    Node* current = head;

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (current && current->key == key) {
        current->value = value;
    } else {
        int rlevel = randomLevel();
        if (rlevel > level) {
            for (int i = level + 1; i <= rlevel; i++) {
                update[i] = head;
            }
            level = rlevel;
        }

        Node* newNode = new Node(key, value, rlevel);
        for (int i = 0; i <= rlevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}

template<typename K, typename V>
bool SkipList<K, V>::remove(K key) {
    std::vector<Node*> update(maxLevel + 1);
    Node* current = head;

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (!current || current->key != key) {
        return false;
    }

    for (int i = 0; i <= level; i++) {
        if (update[i]->forward[i] != current) {
            break;
        }
        update[i]->forward[i] = current->forward[i];
    }

    delete current;

    while (level > 0 && !head->forward[level]) {
        level--;
    }

    return true;
}

template<typename K, typename V>
bool SkipList<K, V>::search(K key, V &value) {
    Node* current = head;

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->key < key) {
            current = current->forward[i];
        }
    }

    current = current->forward[0];

    if (current && current->key == key) {
        value = current->value;
        return true;
    }

    return false;
}

// Explicit template instantiation
template class SkipList<int, int>;
template class SkipList<std::string, std::string>;

