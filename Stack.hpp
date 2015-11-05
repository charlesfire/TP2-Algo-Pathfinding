#ifndef STACK_HPP
#define STACK_HPP

#include "mld.hpp"
#include "Node.hpp"

template<class T>
class Stack final
{
	public:
		Stack<T>();
		~Stack<T>();
		bool IsEmpty()const;
		T* Pop();
		void Push(T* element);
		T* Top()const;
	private:
		Node<T>* first;
};

template<class T>
Stack<T>::Stack() : first(nullptr) {}

template<class T>
Stack<T>::~Stack<T>()
{
	while (first != nullptr)
	{
		Pop();
	}
}

template<class T>
bool Stack<T>::IsEmpty()const
{
    return first == nullptr;
}

template<class T>
T* Stack<T>::Pop()
{
	T* tempElement = nullptr;
	if (first != nullptr)
	{
		Node<T>* temp = first->next;
		tempElement = first->element;
		delete first;
		first = temp;
	}

	return tempElement;
}

template<class T>
void Stack<T>::Push(T* newElement)
{
	Node<T>* newNode = new Node<T>();
	newNode->next = first;
	first = newNode;
	first->element = newElement;
}

template<class T>
T* Stack<T>::Top()const
{
	if (first != nullptr)
		return first->element;
	return nullptr;
}

#endif // STACK_HPP
