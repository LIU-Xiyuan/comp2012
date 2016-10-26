#include <iostream>
#include "Robot.h"

using namespace std;


int main()
{
	cout << "Total number of existing robots = " << Robot::getExisting() << endl;
	cout << "Total number of robots ever produced = " << Robot::getTotal() << endl;

	Robot A("john", "nash");
	Robot B("melody", "pooh");
	Robot C = A + B;
	Robot* D = new Robot("dora", "emon");

	cout << "Total number of existing robots = " << Robot::getExisting() << endl;
	cout << "Total number of robots ever produced = " << Robot::getTotal() << endl;

	cout << endl;
	cout << A << endl;
	cout << B << endl;
	cout << C << endl;

	cout << endl << "Robot 0 goes little crazy..." << endl;
	A.goLittleCrazy();
	cout << A << endl;

	cout << endl << "Robot 1 goes crazy..." << endl;
	B.goCrazy();
	cout << B << endl;

	cout << endl << "Robot 2 goes super crazy..." << endl;
	C.goSuperCrazy();
	cout << C << endl;

	cout << endl << "Delete Robot D... :(" << endl;
	delete D;

	cout << "Total number of existing robots = " << Robot::getExisting() << endl;
	cout << "Total number of robots ever produced = " << Robot::getTotal() << endl;

	return 0;
}
