#include <iostream>
#include "DeliveryCar.h"
using namespace std;

DeliveryCar::DeliveryCar(int nc, Color c, int mile, int charge):Vehicle(nc, c, mile),chargePerMile(charge){}
DeliveryCar::~DeliveryCar(){}

void DeliveryCar::setCharge(int c)
{
	chargePerMile = c;
}

int DeliveryCar::getCharge()
{
	return chargePerMile;
}
