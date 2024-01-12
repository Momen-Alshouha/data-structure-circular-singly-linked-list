
#include "CircularSinglyLinkedList.h"

int main()
{
	CircularSinglyLinkedList<> list, list2, list3;
	
	list.InsertLast(1);
	list.InsertLast(2);	
	list.InsertLast(3);
	list.InsertLast(4);
	list.InsertLast(5);
	list.InsertLast(6);
	list.InsertLast(7);
	list.InsertLast(8);

	cout << "\n--------------------------------\n";
	list.Print();
	list.SplitAtValue(5, list3);
	list.Print();
	list3.Print();
	

}
