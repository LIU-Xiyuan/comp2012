#include "Pig.h"
#include <iostream>
using namespace std;

Pig::Pig(double w, double p, string n):Animal(n), weight(w), ppw(p){}

Pig::~Pig(){}

void Pig::calculatePrice()
{
	Organism::setPrice(weight*ppw);
	cout<<"Pig::calculatePrice() is called!"<<endl;
}
