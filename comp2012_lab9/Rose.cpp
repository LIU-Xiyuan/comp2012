#include <iostream>
#include "Rose.h"
using namespace std;

Rose::Rose(int s):species(s){}

Rose::~Rose(){}

void Rose::calculatePrice()
{
	switch(species)
	{
	case 0:
		Organism::setPrice(100.0);break;
	case 1:
		Organism::setPrice(200.0);break;
	case 2:
		Organism::setPrice(300.0);break;
	case 3:
		Organism::setPrice(400.0);break;
	default:
		Organism::setPrice(0.0);break;
	}
	cout<<"Rose::calculatePrice() is called!"<<endl;
}
