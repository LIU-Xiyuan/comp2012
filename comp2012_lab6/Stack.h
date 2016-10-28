#ifndef STACK_H_
#define STACK_H_

class Stack
{
public:
	Stack();
	~Stack();

	void push(const int& val);
	int pop();
	int top() const;
	bool empty() const;
private:
	int* Top;
	int index;// the number of element in the stack
};



#endif /* STACK_H_ */
