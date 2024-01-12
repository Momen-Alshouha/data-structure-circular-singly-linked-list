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
	short _length = 0;

	Iterator<T> _begin() {
		return Iterator<T>(_head);
	}

	Iterator<T> _end() {
		return Iterator<T>(nullptr);
	}



public:

	CircularSinglyLinkedList();
	~CircularSinglyLinkedList();

	short GetLength() {
		short length = 0;
		if (_head!=nullptr)
		{
			for (Iterator<T> itr = _begin(); itr != _end(); itr.Next())
			{
				if (itr.current_node == _head && length>0) // to avoid going through infinite loop
				{
					break;
				}

				length++;
			}
		}
		return length;
	}

	Node<T>* GetHead() {
		return _head;
	}

	void SetHead(Node<T>* NewHead) {
		_head = NewHead;
	}

	Node<T>* GetTail() {
		return _tail;
	}

	void SetTail(Node<T>* NewTail) {
		_tail = NewTail;
	}

	// proprties
	__declspec(property(get = GetLength)) short length; // read only 
	__declspec(property(get = GetHead, put = SetHead)) Node<T>* head;
	__declspec(property(get = GetTail, put = SetTail)) Node<T>* tail;

	Node<T>* Find(T DataToFind) {
		if (_head!=nullptr)
		{
			for (Iterator<T> itr = _begin(); itr != _end(); itr.current_node = itr.Next())
			{
				if (itr.current_node->data==DataToFind)
				{
					return itr.current_node;
				}
			}
			return nullptr;
		}
	}

	Node<T>* FindByIndex(short index) {
		
		short counter = 0;
		
		if (_head != nullptr)
		{
			for (Iterator<T> itr = _begin(); itr != _end(); itr.current_node = itr.Next())
			{
				if (counter == index)
				{
					return itr.current_node;
				}
			}
		}
		return nullptr;
	}

	Node<T>* FindParent(T DataToFind) {
		
		if (_head != nullptr)
		{
			for (Iterator<T> itr = _begin(); itr != _end(); itr.current_node = itr.Next())
			{
				if (itr.current_node->next->data == DataToFind)
				{
					return itr.current_node;
				}
			}
			return nullptr;
		}
	}

	bool IsExisit(T DataToCheck) {
		
		if (_head!=nullptr)
		{
			Node<T>* Temp = Find(DataToCheck); // reuse Find 
			if (Temp!=nullptr)
			{
				return true;
			}
		}

		return false;
	}

	void InsertBegin(T DataToInsert) {
		
		Node<T>* NewNode = new (nothrow) Node<T>(DataToInsert);

		if (_head == nullptr) {
			_head = _tail = NewNode;
		}
		else {
			NewNode->next = _head;
			_head = NewNode;
			_tail->next = _head; 
		}
		_length++;
	}

	void InsertLast(T DataToInsert) {
		
		Node<T>* NewNode = new Node<T>(DataToInsert);

		if (_head==nullptr)
		{
			_head = _tail = NewNode;
		}
		else {
			NewNode->next = _head;
			_tail->next = NewNode;
			_tail = NewNode;
		}
		_length++;
	}



	void Print() {
		if (_head != nullptr) {
			for (Iterator<T> itr = _begin(); itr != _end(); itr.current_node = itr.Next()) {
				cout << itr.current_node->data;
				if (itr.current_node != _tail) {
					cout << " -> ";
				}
			}
			cout << endl;
		}
	}


};


template <typename T>
CircularSinglyLinkedList<T>::CircularSinglyLinkedList() : _head(nullptr), _tail(nullptr) {};

template <typename T>
CircularSinglyLinkedList<T>::~CircularSinglyLinkedList() {
	
	Node<T>* current = _head;

	while (current!=nullptr)
	{
		Node<T>* next = current->next;
		delete current;
		current = (next == _head) ? nullptr : next; // for the purpose of not to go through infinite loop
	}
	_head = nullptr;
	_tail = nullptr;
	_length = 0;
}
