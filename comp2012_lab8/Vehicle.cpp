#include <iostream>
#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle(int nc, Color c, int mile): Engine(nc), color(c), mileage(mile){}

Vehicle::~Vehicle()
{
	cout<<"Calling Vehicle's destructor on the following vehicle:"<<endl;
	Vehicle::print();
	cout<<endl;
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
	return Engine::getNumCylinder();
}

void Vehicle::start()
{
	cout<<"Vehicle with ";
	Engine::Start();
}

void Vehicle::brake(int distance)
{
	cout<<"Vehicle with ";
	Engine::Stop();
	mileage += distance;
	cout<<"Driving distance: "<<distance<<endl;
}

void Vehicle::print() const
{
	cout<<"Engine: "<<Engine::getNumCylinder()<<"\t"<<"color: "<<color<<"\t"<<"Current Mileage: "<<mileage<<endl;
}
