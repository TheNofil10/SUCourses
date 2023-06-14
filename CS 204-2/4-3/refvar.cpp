#include <iostream> 
using namespace std; 

int main () {
    
	double a = 3.1415927; 
	double &b = a; 	// b is a 	
	b = 89;
	cout << "a contains: " << a << endl<<endl; 	// Displays ?
	// Decomment the following two lines to see that rebinding is not possible
	// double c = 2.71;
	// &b = c;

	// Decomment the following block to see the effect of reassignment to a reference variable
	/*double c = 2.71;
	b = c;
	cout << "a contains: " << a << endl;
	cout << "b contains: " << b << endl;
	cout << "c contains: " << c << endl;*/

	// Decomment the following block to see the effect of assignment of a reference variable to a reference variable
	/*double c = 2.71;
	double & d = c;
	b = d;
	cout << "a contains: " << a << endl;
	cout << "b contains: " << b << endl;
	cout << "c contains: " << c << endl;
	cout << "d contains: " << d << endl;*/

	
	// Decomment the following block to see what happens when a ref. var. is defined as const
	/*double x = 4.12;
	const double & y = x;
	//y = 3.5;   // syntax error, const ref. var. cannot be changed
	//x = 3.5;   // legal syntax
	//double & z = y;  // syntax error, const-ref. var. cannot be assigned to a regular ref. var.
	cout << endl;
	cout << "x contains: " << x << endl;
	cout << "y contains: " << y << endl;*/

	return 0; 
} 
