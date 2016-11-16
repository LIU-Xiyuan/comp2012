#include <iostream>
#include "PoliceCar.h"
using namespace std;

PoliceCar::PoliceCar(int nc, Color c, int m, bool action):Car(nc, c, m), inAction(action){}

PoliceCar::~PoliceCar()
{
	cout<<endl;
	cout<<"Calling PoliceCar's destructor on the following police car:"<<endl;
	print();
}

bool PoliceCar::getInAction() const {return inAction;}

void PoliceCar::setInAction(bool action) {inAction=action;}

void PoliceCar::print() const
{
	cout<<"Information about the police car:"<<endl;
	Car::print();
	cout<<"State: ";
	if(getInAction()==0)
		cout<<"not in action"<<endl;
	else
		cout<<"in action"<<endl;
	cout<<endl;
}
