#include <iostream>
#include "Stack.h"

using namespace std;

//Stack Constructor
Stack::Stack()
	:top(nullptr) {}

//Stack Destructor
Stack::~Stack()
{
	stackNode *t;
	
	while(!isEmpty()){
		
		t = top-> next;
		delete top;
		top = t;
	}

	delete top;
}

//Pushes back new elements to the top of the stack
//public
void Stack::push(int r,int c){

	stackNode *node = new stackNode;
	node->r = r;
	node->c = c;

	if(!isEmpty()){

		node->next = top;
		top = node;
	}
	
	else{

		top = node;
		node->next = nullptr;
	}
}

//Pops up elements from the top of the stack
//public
void Stack::pop(int & r,int & c){

	stackNode *t;

	if(!isEmpty()){

		r = top->r;
		c = top->c;
		t = top->next;
		delete top;
		top = t;
		
	}

	else{

		cout<<"Stack is empty!\n";
	}
}

//Returns true if stack is empty
bool Stack::isEmpty(){
	
	return top == nullptr;
}