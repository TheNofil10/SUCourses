#ifndef STACK_H_
#define STACK_H_

template <class object>
class stack{
private:
	struct node{
		node * next;
		object obj;

		node(): next(nullptr){}
		node(object d, node * n=nullptr): next(n), obj(d) {}
		~node(){
			next=nullptr;
			delete next;
		}
	};
	node * header;
	void printHelper(node *);
public:
	stack():header(nullptr){}
	stack(const stack<object> &);
	~stack();
	void push(const object &);
	object pop();
	void makeEmpty();
	bool isEmpty();
	const stack<object> & operator = (const stack<object> &);
	void print();
};

#endif
