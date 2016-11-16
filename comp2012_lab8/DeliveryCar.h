#ifndef DELIVERYCAR_H_
#define DELIVERYCAR_H_

#include "Vehicle.h"

class DeliveryCar: protected Vehicle
{
public:
	DeliveryCar(int nc, Color c, int mile, int charge);
	~DeliveryCar();
	void setCharge(int charge);
	int getCharge();
private:
	int chargePerMile;
};


#endif /* DELIVERYCAR_H_ */
