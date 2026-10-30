#include "AutoPtr.hpp"

template <typename T>
AutoPtr<T>::AutoPtr(T *_m_ptr) : m_ptr(_m_ptr){}

template <typename T>
AutoPtr<T>::~AutoPtr() {
    delete m_ptr;
}
