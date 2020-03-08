#include "DoublyLinkedList.h"

int main() 
{
	DoublyLinkedList L;
	//Adding the node to the list
	L.addAtFront(new Node(3));
	//L.addAtEnd(new Node(5));
	L.addAtEnd(new Node(6));
	L.addAtEnd(new Node(7));
	L.addAtEnd(new Node(8));
	L.addAtEnd(new Node(-2));
	L.addAtEnd(new Node(-6));
	L.addAtEnd(new Node(6));
	L.addAtEnd(new Node(9));
	L.addAtEnd(new Node(0));
	L.addAtEnd(new Node(8));
	L.addAtEnd(new Node(5));

	L.display();
	//L.deleteNode(3);
	//L.addAtFront(new Node(2));
	L.deleteNode(5);

	//Display elements of the Doubly linked list
	L.display();

	////Display the list in reverse order
	L.displayInReverse();
}