#ifndef DYNSTACK_H
#define DYNSTACK_H

struct StackNode{
	int value;
	StackNode *next;
};

class DynIntStack{
private:
	StackNode *top;

public:
	DynIntStack(void);
	void push(int);
	void pop(int &);
	bool isEmpty(void) const;
};
