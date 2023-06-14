#ifndef STACK_H
#define STACK_H
#include <string>

using namespace std;

struct stackNode{

	int r;
	int c;
	stackNode *next;
};

class Stack{

private:
	
	stackNode *top;

public:
	
	Stack();
	~Stack();
	void push(int, int);
	void pop(int &,int &);
	bool isEmpty(void);
};

#endif