#ifndef STACK_HPP
#define STACK_HPP

#include <algorithm>
#include <string>
#include <type_traits>
#include <vector>
#include "Node.hpp"
#include "Square.h"

/// <summary>
/// Conteneur générique permettant l'accès au dernier élément ajouté (LIFO)
/// </summary>
template<class T>
class Stack final
{
	public:	
		Stack<T>();		
		~Stack<T>();		
		bool IsEmpty()const;		
		T* Pop();		
		void Push(T* element);		
		unsigned int Size()const;		
		T* Top()const;
		template<class U = T>
		typename std::enable_if<!std::is_same<Square, U>::value, std::string>::type ToReverseString()const;
		template<class U = T>
		typename std::enable_if<std::is_same<Square, U>::value, std::string>::type ToReverseString()const;
	private:
		Node<T>* first;
		unsigned int size;
};

template<class T>
Stack<T>::Stack() : first(nullptr), size(0) {}

template<class T>
Stack<T>::~Stack<T>()
{
	// Tant que le pointeur sur le premier node ne pointe pas sur nullptr...
	while (first != nullptr)
		Pop(); // On suprime un élément
}

/// <summary>
/// Détermine si l'instance contient des éléments.
/// </summary>
/// <returns>Retourne vrai si l'instance ne contient aucun élément. Retourne faux sinon.</returns>
template<class T>
bool Stack<T>::IsEmpty()const
{
    return first == nullptr;
}

/// <summary>
/// Enlève le premier élément contenu dans l'instance et le retourne.
/// </summary>
/// <returns>
/// Retourne le premier élément de la stack ou nullptr si la stack est vide
/// </returns>
template<class T>
T* Stack<T>::Pop()
{
	// Pointeur sur l'élément à retourner.
	T* tempElement = nullptr;

	// Si le pointeur sur le premier node n'est pas à nullptr...
	if (first != nullptr)
	{
		// On conserve un pointeur sur le second node.
		Node<T>* temp = first->next;

		// On récupère l'élément à retourner.
		tempElement = first->element;

		// On suprime le premier node.
		delete first;

		// Le second node est maintenant devenu le premier.
		first = temp;
		size--;
	}

	return tempElement;
}

/// <summary>
/// Ajoute un élément à la stack.
/// </summary>
/// <param name="element">L'élément à ajouter à la stack.</param>
template<class T>
void Stack<T>::Push(T* newElement)
{
	// On crée un nouveau node.
	Node<T>* newNode = new Node<T>();

	// On fait pointer le suivant du nouveau node sur le premier node de la stack.
	newNode->next = first;

	// Le nouveau node est maintenant devenu le premier.
	first = newNode;

	// On assigne l'élément au nouveau node.
	first->element = newElement;
	size++;
}

/// <summary>
/// Obtient le nombre d'élément de la stack.
/// </summary>
/// <returns>Retourne le nombre d'élément de la stack.</returns>
template<class T>
unsigned int Stack<T>::Size()const
{
	return size;
}

/// <summary>
/// Obtient le premier élément contenu dans la stack.
/// </summary>
/// <returns>Retourne le premier élément contenu dans la stack ou nullptr si la stack est vide.</returns>
template<class T>
T* Stack<T>::Top()const
{
	if (first != nullptr)
		return first->element;
	return nullptr;
}

/// <summary>
/// Obtient une représentation de la stack sous forme de string. Version générique.
/// </summary>
/// <returns>Retourne une string représentant le contenu de la stack.</returns>
template<class T>
template<class U = T>
typename std::enable_if<!std::is_same<Square, U>::value, std::string>::type Stack<T>::ToReverseString()const
{
	// On crée un tableau de string représentant les éléments de la stack sous la forme de string.
	std::vector<std::string> strTab;

	// On crée un pointeur sur le prochain élément à convertir en string.
	Node<T>* temp = first;

	// Tant que le pointeur sur le prochain élément à convertir n'est pas à nullptr...
	while (temp != nullptr)
	{
		// On ajoute une nouvelle string au tableau...
		strTab.push_back(std::to_string(temp->element) + "\n");

		// On obtient le prochain node.
		temp = temp->next;
	}

	// On inverse les éléments.
	std::reverse(strTab.begin(), strTab.end());

	// On combine tous les éléments en unse seule string.
	std::string str = "";
	for (auto subStr : strTab)
		str += subStr;

	return str;
}

/// <summary>
/// Obtient une représentation de la stack sous forme de string. Version spécifique aux Stack de Square.
/// </summary>
/// <returns>Retourne une string représentant le contenu de la stack ou "No solution was found." si la stack est vide.</returns>
template<class T>
template<class U = T>
typename std::enable_if<std::is_same<Square, U>::value, std::string>::type Stack<T>::ToReverseString()const
{
	// Si la stack est vide...
	if (IsEmpty())
		return "No solution was found.";

	// On crée un tableau de string représentant les éléments de la stack sous la forme de string.
    std::vector<std::string> strTab;

	// On crée un pointeur sur le prochain élément à convertir en string.
	Node<T>* temp = first;

	// Tant que le pointeur sur le prochain élément à convertir n'est pas à nullptr...
	while (temp != nullptr)
    {
		// On ajoute une nouvelle string au tableau...
        strTab.push_back("(" + std::to_string(temp->element->x) + ", " + std::to_string(temp->element->y) + ")\n");

		// On obtient le prochain node.
        temp = temp->next;
    }

	// On inverse les éléments.
    std::reverse(strTab.begin(), strTab.end());

	// On combine tous les éléments en unse seule string.
    std::string str = "";
    for (auto subStr : strTab)
        str += subStr;

    return str;
}

#endif // STACK_HPP
