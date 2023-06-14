#ifndef INTQUEUE_H
#define INTQUEUE_H

class IntQueue{
private:
	int *queueArray;
	int queueSize;  //capacity of queue
	int front;
	int rear;
	int numItems;  //# of elements currently in the queue
public:
	IntQueue(int);  //constructor, parameter is capacity
  	void enqueue(int); 
  	void dequeue(int &);
  	bool isEmpty(void) const;
  	bool isFull(void) const;
  	void clear(void);  //removes all elements
};
#endif
