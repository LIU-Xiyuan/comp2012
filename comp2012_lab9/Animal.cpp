#include <iostream>
#include "Animal.h"
using namespace std;

Animal::Animal(string n):name(n){}

Animal::~Animal(){}

string Animal::getName()
{
	return name;
}
