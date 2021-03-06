#include "Stack.h" // TODO: implement a stack using  a dynamic array in Stack.h and Stack.cpp (to be created by yourself)
#include <iostream>
using namespace std;

// checkBox: Determine whether the switch box is routable
bool checkBox(int pins[], int n)
{

	// TODO: Returen true if it is routable, false otherwise
	// Use Stack to implement this part

	Stack s;
	for(int i=0;i<n;i++)
	{
		if(s.top()==pins[i])
			s.pop();
		else
			s.push(pins[i]);
	}
	return s.empty();
}

int main()
{
	int *pins, n;

	cout << "** Assumption: The number of pins is even and it is greater than or equal to  2 **" << endl ;
	cout << "Type number of pins in switch box: " ;
	cin >> n ;

	pins = new int[n];

	cout << "Type numbers for pins 1 through " << n << ": " ;
	for (int i=0;i<n;i++)
		cin >> pins[i] ;

	bool result = checkBox(pins, n);
	if ( result ) {
		cout << "The switch box is routable" << endl ;
	} else {
		cout << "The switch box is NOT routable" << endl ;
	}

	delete [] pins;


	return 0;
}
