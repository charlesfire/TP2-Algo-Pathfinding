#ifndef NODE_HPP
#define NODE_HPP

#include "mld.hpp"

/// <summary>
/// Classe permettant de chainer des éléments.
/// </summary>
template<class T>
struct Node final
{
    Node(T* element = nullptr, Node<T>* next = nullptr) : element(element), next(next) {}

    T* element; // Élément à chainer
    Node* next; // Élément suivant
};

#endif // NODE_HPP
