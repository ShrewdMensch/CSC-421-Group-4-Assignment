#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"

int main() {
	Stack<int> stackOfNumbers;
	stackOfNumbers.push(99);
	stackOfNumbers.push(100);
	stackOfNumbers.push(101);
	cout<< "Height of stack is: " <<stackOfNumbers.getHeight()<<endl; // prints a caption

	Queue Q;
	Q.enqueue(1);
	Q.enqueue(2);
	cout<<endl<<"Length of queue is: "<<Q.length()<<endl;
	Q.dequeue();
	cout<<endl<<"Length of queue is after dequeue: "<<Q.length()<<endl;

	LinkedList lst;
	lst.addAtFront(new Node(1));
	lst.addAtEnd(new Node(2));
	
	cout<<endl<<"No of items on the list: "<<lst.NoOfItems()<<endl;

}
