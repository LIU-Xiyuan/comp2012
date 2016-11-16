#include <iostream>
#include "Car.h"
using namespace std;

Car::Car(int nc, Color c, int mile):engine(nc),color(c),mileage(mile){}

Car::~Car()
{
	cout<<"Calling Car's destructor on the following car:"<<endl;
	Car::print();
}

Color Car::getColor() const
{
	return color;
}

int Car::getMileage() const
{
	return mileage;
}

int Car::getEngine() const
{
	return engine.getNumCylinder();
}

void Car::start()
{
	cout<<"Car with ";
	engine.Start();
}

void Car::brake(int distance)
{
	cout<<"Car with ";
	engine.Stop();
	mileage += distance;
}

void Car::print() const
{
	cout<<"Engine: "<<engine.getNumCylinder()<<"\t"<<"color: "<<color<<"\t"<<"Current Mileage: "<<mileage<<endl;
}
