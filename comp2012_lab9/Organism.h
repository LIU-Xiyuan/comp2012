/*
 * Organism.h
 *
 *  Created on: Nov 21, 2016
 *      Author: sam
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_

#include <iostream>
using namespace std;

class Organism
{
private:
	double price;
public:
	Organism(double p = 0.0);
	virtual ~Organism();
	void setPrice(double p);
	double getPrice();
	virtual void calculatePrice() = 0;
};



#endif /* ORGANISM_H_ */
