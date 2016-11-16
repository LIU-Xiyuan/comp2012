#ifndef VEHICLE_H_
#define VEHICLE_H_

#include "Engine.h"

class Vehicle: private Engine
{
private:
	Engine engine;  // Car has-a engine
	Color color;	// Color of the car
	int mileage;	// Total mileage

public:
	Vehicle(int nc, Color color, int mileage); // Constructor
	Color getColor() const;
	int getMileage() const;
	int getEngine() const;
	~Vehicle();
	void start();
	void brake(int distance);
	void print() const;
};



#endif /* VEHICLE_H_ */
