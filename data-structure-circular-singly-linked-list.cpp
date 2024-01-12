
#include "CircularSinglyLinkedList.h"

int main()
{
	CircularSinglyLinkedList<> list;
	
	list.InsertLast(1);
	list.InsertLast(2);	
	list.InsertLast(3);
	list.InsertLast(4);
	list.Print();
	list.Reverse();
	list.Print();
}
