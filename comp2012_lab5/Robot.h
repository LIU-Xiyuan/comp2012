#ifndef ROBOT_H_
#define ROBOT_H_

#include <string>
#include <iostream>
using namespace std;


class Robot
{
public:
	Robot(string firstName, string lastName);
	~Robot();

	//TODO1: define a static member function getExisting that returns the value stored in the "existing" static variable
	static int getExisting()
	{
		return existing;
	}

	//TODO2: define a static member function getTotal that returns the value stored in the "total" static variable
	static int getTotal()
	{
		return total;
	}

	//*** You will implement the following member functions in the cpp file...

	//convert all letters to upper-case in both the firstName and lastName
	void goLittleCrazy();

	//reverse the letters in both the firstName and lastName
	void goCrazy();

	//interleave the letters of the firstName and lastName; the interleaving result will be stored in both the firstName and lastName; see sample output
	//for example, for "melody nash",
	//you should take the first letter in the first name "m", then take the first letter of the last name "n", then take the second letter of the first name "e", then take the second letter of the last name "a", and so on
	//the result is then "m" + "n" + "e" + "a" + "l" + "s" + "o" + "h" + "d" + "y"
	//note that the first name is longer than the last name, so the remaining of the first name will be appended to the end
	//similarly, if the last name is longer than the first name, append the remaining of the last name to the end
	void goSuperCrazy();

	//implement the operator+ for Robot objects so that
	//C = A + B
	//produces the robot C with the firstName taken from the robot B, and the lastName taken from robot A; see sample output
	Robot operator+(const Robot& another) const;

	//cout << robot; should output the following for the "robot" Robot object
	//Robot INDEX: FIRSTNAME LASTNAME
	//e.g. "Robot 1: melody pooh"
    friend ostream& operator<< (ostream& os, const Robot& r);

private:
	string firstName; //first name of the robot
	string lastName; //last name of the robot
	int index; //first robot should have the index of 0, second robot should have the index of 1, and so on.

	//TODO3: define a static member "existing" that stores the number of existing robots (excluding those that are not destructed)
	static int existing;

	//TODO4: define a static member "total" that stores the total number of produced robots ever produced (including those that have been destructed)
	static int total;
};


#endif /* ROBOT_H_ */
