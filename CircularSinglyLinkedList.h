#pragma once
#include "Node.h"
#include "Iterator.h"
#include <iostream>
using namespace std;

template<typename T = int> // int is default template argument 
class CircularSinglyLinkedList
{
	Node<T>* _head;
	Node<T>* _tail;

	Iterator<T> _begin() {
		return Iterator<T>(_head);
	}

	Iterator<T> _end() {
		return Iterator<T>(nullptr);
	}

public:

	CircularSinglyLinkedList();
	~CircularSinglyLinkedList();

};


template <typename T>
CircularSinglyLinkedList<T>::CircularSinglyLinkedList() : _head(nullptr), _tail(nullptr) {};

template <typename T>
CircularSinglyLinkedList<T>::~CircularSinglyLinkedList() // destructor to free memory
{
	Iterator<T> itr = _begin();

	while (itr != _end()) {
		Node<T>* current = itr.current_node;
		itr.Next();
		delete current;
	}
}