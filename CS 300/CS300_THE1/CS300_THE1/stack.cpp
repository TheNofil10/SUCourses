#include "stack.h"
#include <iostream>
using namespace std;

template<class object>
stack<object>::stack(const stack<object> & rhs){
	header=NULL;
	rhs=*this;
}

template<class object>
stack<object>::~stack(){
	makeEmpty();
}

template<class object>
void stack<object>::push(const object & pushedObj){
	node * pushed=new node(pushedObj, header);
	header=pushed;
}

template<class object>
object stack<object>::pop(){
	node * deleted = header;
	object returnValue = deleted->obj;
	header=header->next;
	deleted = NULL;
	delete deleted;
	return returnValue;
}

template<class object>
bool stack<object>::isEmpty(){
	return header == NULL;
}

template<class object>
void stack<object>::makeEmpty(){
	while(!isEmpty())
		pop();
}

template<class object>
const stack<object> & stack <object> :: operator =  (const stack<object> & rhs){
	makeEmpty();
	if(rhs.isEmpty())
		return * this;
	header=new node(rhs.header->obj);
	node *lCurrent=header, *rCurrent=rhs.header;
	for( rCurrent = rCurrent->next; rCurrent != NULL; rCurrent = rCurrent->next )
		lCurrent = lCurrent->next = new node( rCurrent->element );
}

template<class object>
void stack<object>::printHelper(node * ptr){
	if(ptr->next != NULL)
		printHelper(ptr->next);
	cout << ptr->obj << ", ";
}

template<class object>
void stack<object>::print(){
	if(!isEmpty()){
		node * ptr=header;
		if(ptr->next != NULL)
			printHelper(ptr->next);
		cout << ptr->obj;
	}
}
