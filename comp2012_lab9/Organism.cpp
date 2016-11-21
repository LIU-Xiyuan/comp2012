#include "Organism.h"
using namespace std;

Organism::Organism(double p):price(p){}

Organism::~Organism(){}

void Organism::setPrice(double p){price = p;}

double Organism::getPrice(){return price;}
