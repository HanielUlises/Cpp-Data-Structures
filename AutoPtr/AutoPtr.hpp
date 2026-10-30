#pragma once 

template <typename T>
class AutoPtr {
        T *m_ptr;
    public:
        AutoPtr(T *_mptr);
        ~AutoPtr();
};
