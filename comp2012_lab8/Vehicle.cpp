#include <iostream>
#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle(int nc, Color c, int mile):engine(nc), color(c),mileage(mile){}

Vehicle::~Vehicle()
{
	cout<<"Calling Car's destructor on the following car:"<<endl;
	Vehicle::print();
}

Color Vehicle::getColor() const
{
	return color;
}

int Vehicle::getMileage() const
{
	return mileage;
}

int Vehicle::getEngine() const
{
	return engine.getNumCylinder();
}

void Vehicle::start()
{
	cout<<"Car with ";
	engine.Start();
}

void Vehicle::brake(int distance)
{
	cout<<"Car with ";
	engine.Stop();
	mileage += distance;
}

void Vehicle::print() const
{
	cout<<"Engine: "<<engine.getNumCylinder()<<"\t"<<"color: "<<color<<"\t"<<"Current Mileage: "<<mileage<<endl;
}
