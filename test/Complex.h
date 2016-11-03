/*
 * Complex.h
 *
 *  Created on: 29 Oct 2016
 *      Author: sam
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using namespace std;

class Complex
{
private:
	float real; float imag;
public:
	Complex(float r,float i){real=r;imag=i;}
	void print(){cout<<"real: "<<real<<", imag: "<<imag<<endl;}
	Complex add1(const Complex& x)
	{
		real+=x.real;imag+=x.imag;
		return (*this);
	}
	Complex* add2(const Complex& x)
	{
		real+=x.real;imag+=x.imag;
		return this;
	}
	Complex& add3(const Complex& x)
	{
		real+=x.real;imag+=x.imag;
		return (*this);
	}
};



#endif /* COMPLEX_H_ */
