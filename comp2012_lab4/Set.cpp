#include "Set.h"
using namespace std;

// Default constructor: Construct an empty set
Set::Set()
{
	size=0;
	elements=NULL;
}

// Other constructor: Initialize the data members with the given parameters
Set::Set(const int _elements[], int _size)
{
	size=_size;
	elements=new int[size];
	for(int i=0;i<size;i++)
		elements[i]=_elements[i];
}

// Copy constructor: Perform deep copying
// Hint: Make use of assignment operator function
Set::Set(const Set& s)
{
	size=s.size;
	elements=new int[size];
	for(int i=0;i<size;i++)
		elements[i]=s.elements[i];
}

// Destructor: De-allocate dynamic memory
Set::~Set()
{
	if(elements!=NULL)
	{
		delete []elements;
		elements=NULL;
	}
}

// Return the cardinality of the set, i.e., the size
int Set::cardinality() const
{
	if(size!=0)
		return size;
	else return 0;
}

// Return the element's index if it exists. Otherwise return -1
// Notice: you has to process the data type: int, string ...
// You has to also consider how to process the datatype: float and double
// Hint: You can consider doing template specialization for float and double
int Set::findElement(const int& element) const
{
	if(size!=0)
		for(int i=0;i<size;i++)
			if(elements[i]==element)
				return i+1;
	return -1;
}

// Return true if the element exists, otherwise return false
bool Set::isExist(const int& element) const
{
	if(size!=0)
		for(int i=0;i<size;i++)
			if(elements[i]==element)
				return true;
	return false;
}

// Allocate a new array of size "size+1", copy all the existing elements over and
// add the new element to the last position of the new array
void Set::addElement(const int& element)
{
	size+=1;
	int* _elements=new int[size];
	for(int i=0;i<size-1;i++)
		_elements[i]=elements[i];
	_elements[size-1]=element;
	delete []elements;
	elements=_elements;
}

// Check if the element is in the set.
// If it is in the set, allocate a new array and copy all the existing elements over except
// the element to be deleted.
// Return true if the element is found and deleted. Otherwise return false
bool Set::removeElement(const int& element)
{
	if(this->isExist(element))
	{
		int* _elements=new int[size-1];
		for(int i=0;i<this->findElement(element)-1;i++)
			_elements[i]=elements[i];
		for(int i=this->findElement(element)-1;i<size-1;i++)
			_elements[i]=elements[i+1];
		delete []elements;
		elements=_elements;
		return true;
	}
	return false;
}

// Overload operator+ to support union operation of two set objects
// Note: Resulting set of A + B = { x : x in A or x in B }
Set Set::operator+ (const Set&s)
{
	int _size=size;
	bool inhere=false;
	for(int i=0;i<s.size;i++)
		{
			for(int j=0;j<size;j++)
				if(elements[j]==s.elements[i])
					inhere=true;
			if(!inhere)
				_size+=1;
			inhere=false;
		}
	int* _elements=new int[_size];
	int k=0;
	bool ishere=false;
	for(;k<size;k++)
		_elements[k]=elements[k];
	for(int i=0;i<s.size;i++)
		{
			for(int j=0;j<size;j++)
				if(elements[j]==s.elements[i])
					ishere=true;
			if(!ishere)
				{
					_elements[k++]=s.elements[i];
					ishere=false;
				}
			ishere=false;
		}
	Set S(_elements,_size);
	return S;
}


// Overload operator^ to support intersect operation of two set objects
// Note: Resulting set of A ^ B = { x : x in A and x in B }

Set Set::operator^ (const Set&s)
{
	int _size=0;
	for(int i=0;i<s.size;i++)
		for(int j=0;j<size;j++)
			if(elements[j]==s.elements[i])
				_size+=1;
	int* _elements=new int[_size];
	int k=0;
	for(int i=0;i<s.size;i++)
		for(int j=0;j<size;j++)
			if(elements[j]==s.elements[i])
				_elements[k++]=s.elements[i];
	Set S(_elements,_size);
	return S;
}

// Overload operator- to support difference operation of two set objects
// Note: Resulting set of A - B = { x : x in A and x not in B }

Set Set::operator- (const Set&s)
{
	int _size=0;
	for(int i=0;i<s.size;i++)
		for(int j=0;j<size;j++)
			if(elements[j]==s.elements[i])
				_size+=1;
	_size=size-_size;
	int* _elements=new int[_size];
	int k=0;
	bool inhere=false;
	for(int i=0;i<size;i++)
		{
			for(int j=0;j<s.size;j++)
				if((elements[i]==s.elements[j]))
					inhere=true;
			if(!inhere)
				_elements[k++]=elements[i];
			inhere=false;
		}

	Set S(_elements,_size);
	return S;
}

// Overload assignment operator function
// Note: Deep copying is required

Set Set::operator= (const Set&s)
{
	size=s.size;
	if(elements!=NULL)
		delete []elements;
	elements=new int[size];
	for(int i=0;i<size;i++)
		elements[i]=s.elements[i];
	return *this;
}

// Overload operator<< to allow output of objects in Set type
ostream& operator<< (ostream& os, const Set& a)
{
	if(a.size!=0)
	{
		os<<'{';
		for(int i=0;i<a.size-1;i++)
			{
				os<<a.elements[i];
				os<<", ";
			}
		os<<a.elements[a.size-1];
		os<<'}';
	}
	return os;
}
