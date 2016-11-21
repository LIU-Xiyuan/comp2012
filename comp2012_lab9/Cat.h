/*
 * Cat.h
 *
 *  Created on: Nov 21, 2016
 *      Author: sam
 */

#ifndef CAT_H_
#define CAT_H_

#include <iostream>
#include "Animal.h"
using namespace std;

class Cat:public Animal
{
private:
	int species;
public:
	Cat(int s, string n);
	~Cat();
	void calculatePrice();
};



#endif /* CAT_H_ */
