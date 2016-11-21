#include <iostream>
#include "Animal.h"
using namespace std;

class Pig: public Animal
{
private:
	double weight;
	double ppw; // price per weight
public:
	Pig(double w, double p, string n);
	~Pig();
	void calculatePrice();
};
