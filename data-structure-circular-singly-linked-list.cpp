
#include "CircularSinglyLinkedList.h"

int main()
{
	CircularSinglyLinkedList<> list,list2;
	
	list.InsertLast(1);
	list.InsertLast(2);	
	list.InsertLast(3);
	list.InsertLast(4);


	list2.InsertLast(1);
	list2.InsertLast(2);
	list2.InsertLast(3);
	list2.InsertLast(4);

	list.Concat(list2);

	list.Print();
	cout << list.length << endl;
	cout << list.tail->next->data << endl;



}
