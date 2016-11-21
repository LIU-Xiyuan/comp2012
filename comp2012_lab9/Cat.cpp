#include <iostream>
#include "Cat.h"
using namespace std;

Cat::Cat(int s, string n):Animal(n), species(s){}

Cat::~Cat(){}

void Cat::calculatePrice()
{
	switch(species)
	{
	case 0:
		Organism::setPrice(50.0);break;
	case 1:
		Organism::setPrice(100.0);break;
	case 2:
		Organism::setPrice(150.0);break;
	default:
		Organism::setPrice(0.0);break;
	}
	cout<<"Cat::calculatePrice() is called!"<<endl;
}
