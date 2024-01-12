
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
	cout << list.tail->next->data << endl;
	cout << list.Find(2) << endl;
	cout << list.FindParent(21) << endl;
	cout << boolalpha << list.IsExisit(100) << endl;
	cout << boolalpha << list.IsExisit(5) << endl;
	cout << list.FindByIndex(121) << endl;
}
