
#include "CircularSinglyLinkedList.h"

int main()
{
	CircularSinglyLinkedList<> list,list2;
	
	list.InsertLast(1);
	list.InsertLast(2);	
	list.InsertLast(3);
	list.InsertLast(4);


	list2.InsertLast(5);
	list2.InsertLast(6);
	list2.InsertLast(7);
	list2.InsertLast(8);

	list.Concat(list2);

	list.Print();
	cout << list.length << endl;
	cout << list.tail->next->data << endl;
	list.Update(1, 99);
	list.Print();
	list.Swap(99, 8);
	list.Swap(6, 8);
	list.Print();

}
