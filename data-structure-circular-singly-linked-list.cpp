
#include "CircularSinglyLinkedList.h"

int main()
{
	CircularSinglyLinkedList<> list;
	
	list.InsertLast(4);
	list.InsertLast(2);	
	list.InsertLast(3);
	list.InsertLast(9);
	list.InsertLast(-1);
	list.InsertLast(11);
	list.InsertLast(6);
	list.InsertLast(7);
	list.InsertLast(99);
	list.InsertLast(10);
	list.Print();
	list.BubbleSortDesc();
	list.Print();
	

}
