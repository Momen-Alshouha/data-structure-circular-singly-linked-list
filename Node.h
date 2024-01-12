#pragma once

template <typename T = int> // int is default template argument
class Node {

	T _data;
	Node<T>* _ptrToNext;

public:

	Node(T Data) :_data(Data), _ptrToNext(nullptr) {};

	T GetData() {
		return _data;
	}

	void SetData(T Data) {
		_data = Data;
	}

	Node<T>* GetNext() {
		return _ptrToNext;
	}

	void SetNext(Node<T>* ptrToNext) {
		_ptrToNext = ptrToNext;
	}

	// proprties
	__declspec(property(get = GetData, put = SetData)) T data;
	__declspec(property(get = GetNext, put = SetNext)) Node<T>* next;

};