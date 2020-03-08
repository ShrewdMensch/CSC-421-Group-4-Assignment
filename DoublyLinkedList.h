#include <iostream>
#include "Node.h"
using namespace std;

class DoublyLinkedList {

Node *head;

public:
//Constructor
DoublyLinkedList();

//declaring the functions

//function to add Node at front
int addAtFront(Node *n);

//function to check whether Linked list is empty
bool isEmpty();

//function to add Node at the End of list
int addAtEnd(Node *n);

//function to search a value
Node* search(int k);

//function to delete any Node
Node* deleteNode(int x);

//function to get last Node
Node* getLastNode();

//function to print the LinkedList elements
void display();

//function to print the LinkedList elements
void displayInReverse();

};

DoublyLinkedList::DoublyLinkedList()
{
	head = NULL;
}


int DoublyLinkedList :: addAtFront(Node *n) {
	int i = 0;
	if(head == NULL){ head= n; return i;}
	//making the next of the new Node point to Head
	n->next = head;
	//making the new Node the previous of the old Head
	head->previous = n;
	head= n; //Making n the new head
	i++;
	//returning the position where Node is added
	return i;
}

bool DoublyLinkedList :: isEmpty() 
{
	return head == NULL;

}

int DoublyLinkedList :: addAtEnd(Node *n) {
	int i=0;

	//If list is empty
	if(head == NULL) 
	{
		//making the new Node as Head
		head = n;
		i++;
		return i;
	}

	else 
	{
		Node *ptr = head;
		//loops through until the end of the list is reached i.e when ptr->next== NULL
		//for(ptr= head; ptr->next!=NULL;ptr=ptr->next); 
		while( ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next= n; //Putting n next to the last Node i.e making n the new last Node
		n->previous= ptr; //Making n point back to the old last Node, as it previous Node 
	}

}


Node* DoublyLinkedList :: search(int x) 
{
		for(Node *ptr = head; ptr != NULL; ptr= ptr->next) 
			{
				//if x is found
				if(ptr->data == x) 
				{
					return ptr;
					break;  //go out of the for loop when x has been found
				}
			}
		
	return NULL;	//When x is not found
}

Node* DoublyLinkedList :: deleteNode(int x) 
{
	//searching the Node with data x
	Node *n = search(x);
	Node *ptr = head;
	
	//if search(x) returned NULL i.e x was not found
	if (n == NULL) 
	{
		cout <<endl <<x <<" not found on the list, hence no deletion" <<endl; 
		return NULL;
	}

	//if x is found at the head Node
	if(ptr == n) 
	{
		head=head->next;
		return n;
	}

	else 
	{

		/*while(ptr->next != n) 
		{
			ptr = ptr->next;
		}*/
		//loops through until the Node next to ptr contains the value to be deleted i.e when ptr->next== NULL
		for(; ptr->next!=n;ptr=ptr->next); 

		/*Special case ,if the element to delete was found at the last Node*/
		if(n->next==NULL) {ptr->next= NULL;return n; }

		//Otherwise
		//Let ptr points to the next of the deleted node,n
		ptr->next = n->next;
		n->next->previous=  ptr;
		return n;
	}
}



void DoublyLinkedList::display() {

	//If list is empty just return (no element to display)
	if(isEmpty()) return;
	
	cout<<endl;
	for (Node* ptr= head;ptr!=NULL;ptr=ptr->next)
	{
		cout<<(ptr->data)<<endl;
	}
}

void DoublyLinkedList::displayInReverse() {

	//If list is empty just return (no element to display)
	if(isEmpty()) return;

	cout<<"\nList in reverse order"<<endl;
	Node* ptr= head;
	while(ptr->next!=NULL) ptr= ptr->next;
	
	while(ptr!= NULL){
		cout<<ptr->data<<endl;
		ptr=ptr->previous;
	}

		
	
}