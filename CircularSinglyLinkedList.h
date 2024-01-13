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

	short _GetNodeIndex(T Data) {

		short index = 0; 

		if (_head != nullptr)
		{
			for (Iterator<T> itr = _begin(); itr != _end(); itr.current_node = itr.Next())
			{
				if (itr.current_node->data == Data)
				{
					return index;
				}
				index++;
			}
		}

		return -1;// -1 means that node not exisit
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
			if (index<_length)
			{
				for (Iterator<T> itr = _begin(); itr != _end(); itr.current_node = itr.Next())
				{
					if (counter == index)
					{
						return itr.current_node;
					}
					counter++;
				}
			}
		}

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

	void InsertAtIndex(short index,T DataToInsert) {
		if (index<=length)
		{
			if (index==0)
			{
				InsertBegin(DataToInsert);
			}
			else if (index==length) {
				InsertLast(DataToInsert);
			}
			else {
				Node<T>* Temp = FindByIndex(index);
				Node<T>* ParentAtIndex = FindParent(Temp->data);
				Node<T>* NewNode = new Node<T>(DataToInsert);
				NewNode->next = ParentAtIndex->next;
				ParentAtIndex->next = NewNode;
				_length++;
			}
		}
	}

	void InsertBefore(T DataToInsertBefore,T NewData) {
		if (_head!=nullptr)
		{
			short index = _GetNodeIndex(DataToInsertBefore);

			if (index==0)
			{
				InsertBegin(NewData);
			}
			else {
				InsertAtIndex(index, NewData);
			}
		}
	}

	void InsertAfter(T DataToInsertAfter , T NewData) {
		if (_head!=nullptr)
		{
			short index = _GetNodeIndex(DataToInsertAfter);
			if (index==length-1)
			{
				InsertLast(NewData);
			}
			else {
				InsertAtIndex(index + 1,NewData);
			}
		}
	}


	void DeleteFront() {
		
		if (_head != nullptr) {
		
			_head = _head->next;

			if (_head == nullptr) {
				_tail = nullptr;
			}
			else {
				_tail->next = _head;
			}
			
			_length--;
		}
	}


	void DeleteBack() {

		if (_head != nullptr) {
			if (_tail == _head) {
				delete _head;
				_head = _tail = nullptr;
				_length = 0;
			}
			else {
				Node<T>* tailParent = FindParent(_tail->data);
				delete _tail;
				_tail = tailParent;
				_tail->next = _head;
				_length--;
			}
		}

	}

	void DeleteAtIndex(short index) {
		
		if (_head!=nullptr && index>=0 && index<_length)
		{
			if (index==0)
			{
				DeleteFront();
			}
			else if (index==_length-1) {
				DeleteBack();
			}
			else {

				Node<T>* NodeParent = FindByIndex(index - 1);

				if (NodeParent!=nullptr)
				{
					NodeParent->next = NodeParent->next->next;
					_length--;
				}
			}
		}

	}

	void DeleteAllNodesWithSpecificValue(T value) {
		
		CircularSinglyLinkedList<T> newLinkedList;

		for (Iterator<T> itr = _begin(); itr != _end(); itr.current_node = itr.Next()) {
			if (itr.current_node->data != value) {
				newLinkedList.InsertLast(itr.current_node->data);
			}
		}

		Clear(); // clear linked list current instance


		// Copy the elements from the new linked list to the current instance
		for (Iterator<T> itr = newLinkedList._begin(); itr != newLinkedList._end(); itr.current_node = itr.Next()) {
			(*this).InsertLast(itr.current_node->data);
		}

	}

	void SplitAtValue(T SplitValue, CircularSinglyLinkedList<T> &SecondList) {
		
		Node<T>* SplitNode = Find(SplitValue);

		if (_head==nullptr || SplitNode ==nullptr)
		{
			return;
		}

		SecondList.head = SplitNode->next;
		SecondList.tail = _tail;
		SecondList.tail->next = nullptr;

		_tail = SplitNode;
		_tail->next = nullptr;

		SecondList._length = SecondList.GetLength();
		_length -= SecondList.length;

	}

	void BubbleSortAsc() {
		
		if (_head == nullptr || _head == _tail) {
			return;
		}

		bool swapped = false;

		do {
			swapped = false;

			for (Iterator<T> itr = _begin(); itr != _end(); itr.current_node = itr.Next()) {
				if (itr.current_node->next != nullptr && (itr.current_node->data > itr.current_node->next->data ) && itr.current_node->next!=_head) {
					Swap(itr.current_node->data, itr.current_node->next->data);
					swapped = true;
				}
			}

		} while (swapped);
	}

	void BubbleSortDesc() {
		BubbleSortAsc();
		Reverse();
	}


	void Swap(T Data1 , T Data2) {
		
		if (_head!=nullptr)
		{
			Node<T>* Node1 = Find(Data1);
			Node<T>* Node2 = Find(Data2);
			if (Node1 ==nullptr || Node2==nullptr )
			{
				return;
			}
			T tempData = Node1->data;
			Node1->data = Node2->data;
			Node2->data = tempData;
		}
	}

	void Update(T OldValue, T NewValue) {
		Node<T>* NodeToUpdate = Find(OldValue);
		NodeToUpdate->data = NewValue;
	}

	void Concat(CircularSinglyLinkedList<T> &otherList) {
		
		if (_head==nullptr)
		{

			_head = otherList.head;
			_tail = otherList.tail;
			_length = otherList.length;

		}
		else if (otherList.head != nullptr) {
			
			_tail->next = otherList.head;
			otherList.tail->next = _head;
			_tail = otherList.tail;
			_length += otherList.length;

			otherList._head = nullptr;
			otherList._tail = nullptr;
			otherList._length = 0;
		}
	}

	void Reverse() {
	
		CircularSinglyLinkedList<T> newLinkedList;

		for (Iterator<T> itr = _begin(); itr != _end(); itr.current_node = itr.Next())
		{
			newLinkedList.InsertLast(itr.current_node->data);
		}


		Clear();

		for (Iterator<T> itr = newLinkedList._begin(); itr != newLinkedList._end(); itr.current_node = itr.Next())
		{
			(*this).InsertBegin(itr.current_node->data);
		}

	}


	void Clear() {
		while (_head!=nullptr)
		{
			DeleteBack();
		}
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
	while (_head != nullptr) {
		DeleteBack();
	}
}
