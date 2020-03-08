class Node {
public:
int data;
//pointer to the next node
Node* next;
Node* previous;

Node() {
	data = 0;
	next= previous = NULL;
}

Node(int x) {
	data = x;
	next=previous = NULL;
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

Node* getPrevious() {
	return previous;
}

void setPrevious(Node *n) {
	previous = n;
}

};