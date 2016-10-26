#include "Robot.h"
#include <string>

//TODO1: define all the static variables of the Robot class
int Robot::existing=0;
int Robot::total=0;

//TODO2: define the constructor; you MUST use member initialization list
Robot::Robot(string _firstName, string _lastName)
{
	firstName=_firstName;
	lastName=_lastName;
	index=total;
	existing+=1;
	total+=1;
}

Robot::~Robot()
{
	existing-=1;
}

//TODO3: defined all other member functions of the Robot class
void Robot::goLittleCrazy()
{
	for(int i=0;firstName[i]!='\0';i++)
		if(firstName[i]<=122 && firstName[i]>=97)
			firstName[i]-=32;
	for(int i=0;lastName[i]!='\0';i++)
		if(lastName[i]<=122 && lastName[i]>=97)
			lastName[i]-=32;
}

void Robot::goCrazy()
{
	string first=firstName;
	string last=lastName;
	int firstl=firstName.length();
	int lastl=lastName.length();
	for(int i=0;firstName[i]!='\0';i++)
		first[i]=firstName[firstl-i-1];
	for(int i=0;lastName[i]!='\0';i++)
		last[i]=lastName[lastl-i-1];
	firstName=first;
	lastName=last;
}

void Robot::goSuperCrazy()
{
	string name="";
	if(firstName.length()>=lastName.length())
	{
		int i;
		for(i=0;lastName[i]!='\0';i++)
			{
				name+=firstName[i];
				name+=lastName[i];
			}
		for(;firstName[i]!='\0';i++)
			name+=firstName[i];
	}
	else
	{
		int i;
		for(i=0;firstName[i]!='\0';i++)
			{
				name+=firstName[i];
				name+=lastName[i];
			}
		for(;lastName[i]!='\0';i++)
			name+=lastName[i];
	}
	firstName=name;
	lastName=name;
}

Robot Robot::operator+(const Robot& another) const
{
	return Robot(another.firstName,lastName);
}

ostream& operator<< (ostream& os, const Robot& r)
{
	os<<"Robot "<<r.index<<": "<<r.firstName<<" "<<r.lastName;
	return os;
}
