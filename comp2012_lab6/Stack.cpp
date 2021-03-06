#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack()
{
	Top=NULL;
	index=0;
}

Stack::~Stack()
{
	if(index!=0)
	{
		delete []Top;
		Top=NULL;
	}
}

void Stack::push(const int& val)
{
	int* t=new int[index+1];
	for(int i=0;i<index;i++)
		t[i]=Top[i];
	t[index]=val;
	delete Top;
	Top=t;
	index+=1;
}

int Stack::pop()
{
	if(index>0)
	{
		int val=Top[index-1];
		if(index>1)
		{
			int* t=new int[index-1];
			for(int i=0;i<index-1;i++)
				t[i]=Top[i];
			delete Top;
			Top=t;
		}
		else if(index==1)
		{
			delete []Top;
			Top=NULL;
		}
		index-=1;
		return val;
	}
//	else
//		cerr<<"no element in the stack!"<<endl;
	return -1;
}

int Stack::top() const
{
	if(index>0)
		return Top[index-1];
//	else
//		cerr<<"no element in the stack!"<<endl;
	return -1;
}

bool Stack::empty() const
{
	return (index==0);
}
