#include <iostream>
#define SIZE 100
using namespace std;
class Queue
{
int a[100];
int rear; //same as tail
int front; //same as head

public:
Queue()
{
	rear = front = -1;
}

void enqueue(int x); //declaring enqueue, dequeue and display functions
int dequeue();
int length();
void display();
void isPresent(int );
};

void Queue :: enqueue(int x)
{
	if( rear == SIZE-1)
	{
		cout << "Queue is full";
	}

	else
	{
		if (front == -1) front =0; //Set the first element as front
		a[++rear] = x;
	}
}

int Queue :: dequeue()
{
	return a[++front]; //following approach [B], explained above
}

int Queue::length() {
	int i =0;
	for (int j = front; j<=rear; j++)
		i++;
	return i;
}

void Queue::isPresent(int x) {
	for(int i = front; i <= rear; i++)
	{
		if(a[i] == x)
		{
			cout<<x<<" on the queue at location "<<i+1<<endl ;
			return;
		}
		
	}
	cout<<x<<" is not on the queue"<<endl ;
}


void Queue :: display()
{
	int i;
	for( i = front; i <= rear; i++)
	{
		cout << a[i] <<endl;
	}
}