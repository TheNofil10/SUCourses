#ifndef DYNINTQUEUE_H
#define DYNINTQUEUE_H

struct QueueNode{
	int value;
	QueueNode *next;
    QueueNode(){}
    QueueNode(int num, QueueNode *ptr = NULL){
		value = num;
		next = ptr;
	}
};

class DynIntQueue{
private:
	// These track the front and rear of the queue
	QueueNode *front;
	QueueNode *rear;	
public:
	// Constructor
	DynIntQueue(void);
	
	// Member functions
	void enqueue(int);
	void dequeue(int &);
	bool isEmpty(void) const;
	void clear(void);
};
#endif
