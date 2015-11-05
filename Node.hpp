#ifndef NODE_HPP
#define NODE_HPP

#include "mld.hpp"

template<class T>
struct Node final
{
    Node(T* element = nullptr, Node<T>* next = nullptr) : element(element), next(next) {}

    T* element;
    Node* next;
};

#endif // NODE_HPP
