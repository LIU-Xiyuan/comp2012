//SUBMIT THIS
//MAKE SURE THE SPELLING OF THE FILENAME IS EXACTLY Node.cpp

#include "Node.h"

Node::Node(int _value, int _count, Node* _next)
{
	this->value = _value;
	this->count = _count;
	this->next = _next;
}

Node::Node(const Node& another)
{
	value = another.value;
	count = another.count;
	next = NULL;
}

int Node::getValue() const
{
	return this->value;
}

int Node::getCount() const
{
	return this->count;
}

Node* Node::getNext() const
{
	return this->next;
}

void Node::incrementCount()
{
	this->count += 1;
}

void Node::decrementCount()
{
	this->count -= 1;
}

void Node::setNext(Node* _next)
{
	this->next = _next;
}

bool Node::operator==(const Node& another) const
{
	return (another.count == count && another.value == value);
}

bool Node::operator!=(const Node& another) const
{
	return (another.count != count || another.value != value);
}
