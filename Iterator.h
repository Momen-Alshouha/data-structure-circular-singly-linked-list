#pragma once
#include "Node.h"

template<typename T = int> // int is default template argument
class Iterator {

	Node<T>* _currentNode;

public:

	Iterator(Node<T>* CurrentNode) :_currentNode(CurrentNode) {};

	T GetData() { return _currentNode->data; };

	T SetData(T data) { _currentNode->data = data; };

	Node<T>* GetCurrentNode() { return _currentNode; };

	Node<T>* Next() {
		if (_currentNode !=nullptr) // to avoid nullptr points to nullptr case 
		{
			_currentNode = _currentNode->next;
			return _currentNode;
		}
		else {
			return nullptr;
		}
	}

	// != operator overloading for the purpose of using this inside linked list class
	bool operator!=(const Iterator& other) const {
		return _currentNode != other._CurrentNode;
	}

	// proprties
	__declspec(property(get = GetData, put = SetData)) T data;
	__declspec(property(get = GetCurrentNode)) Node<T>* current_node; // read only 

};