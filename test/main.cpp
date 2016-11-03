/*
 * main.cpp
 *
 *  Created on: 29 Oct 2016
 *      Author: sam
 */
#include <iostream>
#include "Complex.h"
using namespace std;

int main()
{
	Complex y(3,4);y.print();

	cout<<endl<<"Return by value"<<endl;
	Complex x(1,2);x.print();
	x.add1(y).add1(y).print();
	x.print();

	cout<<endl<<"Return its pointer by value"<<endl;
	Complex* p=x.add2(y);
	p->add1(y);
	x.print();
	p->print();

	cout<<endl<<"Return by reference"<<endl;
	Complex z(1,2);z.print();
	z.add3(y).add3(y).print();
	z.print();
	return 0;
}
