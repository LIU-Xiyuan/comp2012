/*
 * Animal.h
 *
 *  Created on: Nov 21, 2016
 *      Author: sam
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>
#include "Organism.h"
using namespace std;

class Animal: public Organism
{
private:
	string name;
public:
	Animal(string n);
	~Animal();
	string getName();
};



#endif /* ANIMAL_H_ */
