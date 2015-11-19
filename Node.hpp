#ifndef NODE_HPP
#define NODE_HPP

#include "mld.hpp"

/// <summary>
/// Classe permettant de chainer des �l�ments.
/// </summary>
template<class T>
struct Node final
{
    Node(T* element = nullptr, Node<T>* next = nullptr) : element(element), next(next) {}

    T* element; // �l�ment � chainer
    Node* next; // �l�ment suivant
};

#endif // NODE_HPP
