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