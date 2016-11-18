#include <iostream>
#include "DeliveryCar.h"
using namespace std;

DeliveryCar::DeliveryCar(int nc, Color c, int mile, int charge):Vehicle(nc, c, mile),chargePerMile(charge){}
DeliveryCar::~DeliveryCar()
{
	cout<<"Calling Vehicle's destructor on the following delivery car:"<<endl;
	print();
	cout<<endl;
}

void DeliveryCar::setCharge(int c)
{
	chargePerMile = c;
}

int DeliveryCar::getCharge()
{
	return chargePerMile;
}

void DeliveryCar::start()
{
	Vehicle::start();
}

void DeliveryCar::brake(int distance)
{
	Vehicle::brake(distance);
}

void DeliveryCar::print() const
{
	cout<<"Information of the delivery car:"<<endl;
	Vehicle::print();
	cout<<"Charge per mile: "<<chargePerMile<<endl;
	cout<<"Calculated charges: "<<Vehicle::getMileage()*chargePerMile<<endl;
}
