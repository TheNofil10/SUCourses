#ifndef INTSTACK_H
#define INTSTACK_H

class IntStack{
private:
	int *stackArray;
	int stackSize;
	int top;

public:
	IntStack(int);
	void push(int);
	void pop(int &);
	bool isFull(void) const;
	bool isEmpty(void) const;
};
	
#endif
