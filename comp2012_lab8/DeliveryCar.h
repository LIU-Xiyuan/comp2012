#ifndef DELIVERYCAR_H_
#define DELIVERYCAR_H_

#include "Vehicle.h"

class DeliveryCar: protected Vehicle
{
public:
	DeliveryCar(int nc, Color c, int mile, int charge);
	virtual ~DeliveryCar();
	void setCharge(int charge);
	int getCharge();
	void start();
	void brake(int distance);
	void print() const;
private:
	int chargePerMile;
};


#endif /* DELIVERYCAR_H_ */
