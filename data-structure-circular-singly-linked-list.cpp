
#include "CircularSinglyLinkedList.h"

int main()
{
	CircularSinglyLinkedList<> list;
	list.InsertBegin(1);
	list.InsertBegin(2);
	list.InsertBegin(3);
	list.InsertBegin(4);
	list.InsertLast(5);
	list.Print();
	cout << list.length << endl;
	cout << list.FindByIndex(1) << endl;;
	cout << list.FindByIndex(0) << endl;;
	list.InsertAtIndex(0, 19);
	list.InsertAtIndex(1, 199);
	list.InsertBefore(19, 777);
	list.InsertAfter(19, 22);
	list.InsertAfter(5, 444);
	list.Print();
	cout << list.tail->next->data << endl;
	cout << list.head->data << endl;
}
