#pragma once
#include "Node.h"

template<typename T = int> // int is default template argument
class Iterator {

	Node<T>* _currentNode;
	Node<T>* _head;
public:

	Iterator(Node<T>* CurrentNode) :_currentNode(CurrentNode){
		_head = CurrentNode;
	};

	T GetData() { return _currentNode->data; };

	T SetData(T data) { _currentNode->data = data; };

	Node<T>* GetCurrentNode() { return _currentNode; };
	
	void SetCurrentNode(Node<T>* current) {
		_currentNode = current;
	};


	Node<T>* Next() {
		if (_currentNode !=nullptr)
		{
			_currentNode = _currentNode->next;

			if (_currentNode==_head) // to avoid infinite loop
			{
				return nullptr;
			}

			return _currentNode;
		}
		else {
			return nullptr;
		}
	}

	// != operator overloading for the purpose of using this inside linked list class
	bool operator!=(const Iterator& other) const {
		return _currentNode != other._currentNode;
	}

	// proprties
	__declspec(property(get = GetData, put = SetData)) T data;
	__declspec(property(get = GetCurrentNode , put=SetCurrentNode)) Node<T>* current_node;

};