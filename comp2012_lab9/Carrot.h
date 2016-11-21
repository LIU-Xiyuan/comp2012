/*
 * Carrot.h
 *
 *  Created on: Nov 21, 2016
 *      Author: sam
 */

#ifndef CARROT_H_
#define CARROT_H_

#include <iostream>
#include "Plant.h"
using namespace std;

class Carrot: public Plant
{
private:
	double weight;
	double ppw;
public:
	Carrot(double weight, double p);
	~Carrot();
	void calculatePrice();
};

#endif /* CARROT_H_ */
