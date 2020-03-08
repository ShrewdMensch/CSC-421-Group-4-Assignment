#include <iostream>
#include "Node.h"
using namespace std;

class LinkedList {
public:
Node *head;
//declaring the functions

//function to add Node at front
int addAtFront(int);

//function to check whether Linked list is empty
bool isEmpty();

//function to add Node at the End of list
int addAtEnd(int);

//function to search a value
Node* search(int k);

//function to delete any Node
Node* deleteNode(int x);

//function to get last Node
Node* getLastNode();

//function to print the LinkedList elements
void display();

//function to sort the LinkedList
void sort();

//function to merge the LinkedList with another LinkedList
LinkedList merge( LinkedList );

//Constructor
LinkedList();
};

LinkedList::LinkedList()
{
	head = NULL;
}

int LinkedList :: addAtFront(int num) {
	Node* n= new Node(num);
	int i = 0;
	//making the next of the new Node point to Head
	n->next = head;
	//making the new Node as Head
	head = n;
	i++;
	//returning the position where Node is added
	return i;
}

bool LinkedList :: isEmpty() 
{
	return head == NULL;

}

int LinkedList :: addAtEnd(int num) {
	Node* n = new Node(num);
	int i=0;

	//If list is empty
	if(head == NULL) 
	{
		//making the new Node as Head
		head = n;
		i++;
		//making the next pointe of the new Node as Null
		n->next = NULL;
		return i;
	}

	else 
	{
		//getting the last node
		Node *n2 = getLastNode();
		n2->next = n; //Making the last Node point to the new Node
		n->next=NULL; //Making the new Node the last Node
	}

}

Node* LinkedList :: getLastNode() {
	//creating a pointer pointing to Head
	Node* ptr = head;
	//Iterating over the list till the node whose Next pointer points to null
	//Return that node, because that will be the last node.
	while(ptr->next!= NULL)
	{
		//if Next is not Null, take the pointer one step forward
		ptr = ptr->next;
	}
	return ptr;
}

Node* LinkedList :: search(int x) 
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

Node* LinkedList :: deleteNode(int x) 
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

		while(ptr->next != n) 
		{
			ptr = ptr->next;
		}

		//Let ptr points to the next of the deleted node,n
		ptr->next = n->next;
		return n;
	}
}

void LinkedList::sort() {
	Node* front= head;
	Node* current= head;
	Node* insertionPointer= head;
	while(current!=NULL) 
	{
		insertionPointer= head;
		while(insertionPointer!=current)
		{
			if(insertionPointer->data > current->data) 
			{
				int temp= current->data;
				current->data= insertionPointer->data;
				insertionPointer->data= temp;
		}
			else
			{
				insertionPointer= insertionPointer->next;
			}
		}
		current= current->next;
	}
}

LinkedList LinkedList::merge(LinkedList lst) {
	LinkedList mergedList;

	if(lst.head!=NULL) 
	{
		for(Node *ptr = head; ptr!=NULL; ptr= ptr->next) {
			mergedList.addAtEnd(ptr->data);
		}

		for(Node *ptr = lst.head; ptr!=NULL; ptr= ptr->next) {
			mergedList.addAtEnd(ptr->data);
		}

		mergedList.sort();
	}

	return mergedList;
}

void LinkedList::display() {

	//If list is empty just return (no element to display)
	if(isEmpty()) return;
	
	for (Node* ptr= head;ptr!=NULL;ptr=ptr->next)
	{
		cout<<(ptr->data)<<endl;
	}
}

int main() 
{
	LinkedList L;
	LinkedList L2;

	//Adding elements to the list (odd numbers)
	L.addAtEnd(1);
	L.addAtEnd(3);
	L.addAtEnd(5);
	L.addAtEnd(7);
	L.addAtEnd(9);

	//Adding elements to the list (even numbers)
	L2.addAtEnd(2);
	L2.addAtEnd(4);
	L2.addAtEnd(6);
	L2.addAtEnd(8);
	L2.addAtEnd(10);

	//Display elements of the linked list ,L
	cout<<"Elements in LinkedList L: "<<endl;
	L.display();

	//Display elements of the linked list ,L2
	cout<<endl<<"Elements in LinkedList L2: "<<endl;
	//L2.deleteNode(10);
	L2.display();

	//Merge Linked list
	LinkedList merger= L.merge(L2);
	//Display the sorted MergedList 
	cout<<endl<<"After merging L and L2 then sorting it"<<endl;
	merger.display();

	//Display elements of the linked list ,L
	cout<<endl<<"Elements in LinkedList L after the merger (still remain the same): "<<endl;
	L.display();
}