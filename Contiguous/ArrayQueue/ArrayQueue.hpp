#pragma once

template <typename T>
class ArrayQueue {
    public:
        bool add(T x);
        T remove();
        void resize();

    private:
        int j;
        int n;
        int capacity;
        T a[];        
};
