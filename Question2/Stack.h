#include <iostream>

using namespace std;

template <typename T>
class Stack {
public:
	explicit Stack (int =10);


	bool isEmpty() {
		return top==-1;
	}

	bool isFull() {
		return top==size-1;
	}

	void push (T val) {
		if(!isFull() ) {
			component[top++] = val;
		}

	}

	T pop () {
		if(!isEmpty() ) {
			return component[top--];
		}
	}

	int getHeight() {
		return top+1;
	}

	int getSize() {
		return size;
	}

private:

	int size;
	int top;
	T* component;
};

template <typename T>
Stack<T>::Stack(int s):size(s),top(-1) {
		//indicate stack is initially empty
		component = new T[size];
	}