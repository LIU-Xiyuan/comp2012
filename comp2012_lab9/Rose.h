/*
 * Rose.h
 *
 *  Created on: Nov 21, 2016
 *      Author: sam
 */

#ifndef ROSE_H_
#define ROSE_H_

#include <iostream>
#include "Plant.h"
using namespace std;

class Rose: public Plant
{
private:
	int species;
public:
	Rose(int s);
	~Rose();
	void calculatePrice();
};



#endif /* ROSE_H_ */
