#include "ArrayQueue.hpp"

#include <numeric>

template <typename T>
bool ArrayQueue<T>::add(T x) {
    if(n + 1 > capacity) resize();
    a[(j + n) % capacity] = x;
    n++;
    return true;
}

template <typename T>
T ArrayQueue<T>::remove() {
    T x = a[j];
    j = (j + 1) % capacity;
    n--;
    if(capacity >= 3 * n) resize();
    return x;
}

template <typename T>
void ArrayQueue<T>::resize() {
    T *b = new T[std::max(1, 2*n)];

}
