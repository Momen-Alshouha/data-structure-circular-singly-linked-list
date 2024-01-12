
#include "CircularSinglyLinkedList.h"

int main()
{
	CircularSinglyLinkedList<> list;
	
	list.InsertLast(1);
	list.InsertLast(1);	
	list.InsertLast(1);
	list.InsertLast(4);
	list.DeleteAllNodesWithSpecificValue(10);
	cout<<list.tail->data << endl;
	list.Print();
}
