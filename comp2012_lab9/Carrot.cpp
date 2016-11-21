#include <iostream>
#include "Carrot.h"
using namespace std;

Carrot::Carrot(double w, double p):Plant(), weight(w), ppw(p){}

Carrot::~Carrot(){}

void Carrot::calculatePrice()
{
	Organism::setPrice(weight*ppw);
	cout<<"Carrot::calculatePrice() is called!"<<endl;
}
