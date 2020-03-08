#include <iostream>

using namespace std;

class Node {
public:
int data;
//pointer to the next node
Node* next;

Node() {
	data = 0;
	next = NULL;
}

Node(int x) {
	data = x;
	next = NULL;
}


int getData() {
return data;
}

void setData(int x) {
	data = x;
}

Node* getNext() {
	return next;
}

void setNext(Node *n) {
	next = n;
}

};

class LinkedList {
public:
Node *head;
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

//Fucntion to get length of list
int NoOfItems();

//function to print the LinkedList elements
void display();

//Constructor
LinkedList();
};

LinkedList::LinkedList()
{
	head = NULL;
}

int LinkedList :: addAtFront(Node *n) {
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

int LinkedList :: addAtEnd(Node *n) {
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

int LinkedList::NoOfItems() {
	int count=0;
	for (Node* ptr= head;ptr!=NULL;ptr=ptr->next)
		count++;
	return count;
}


void LinkedList::display() {

	//If list is empty just return (no element to display)
	if(isEmpty()) return;
	
	for (Node* ptr= head;ptr!=NULL;ptr=ptr->next)
	{
		cout<<(ptr->data)<<endl;
	}
}
