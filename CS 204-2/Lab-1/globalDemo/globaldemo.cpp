#include <iostream>
using namespace std;

int a = 0, b = 5, c = 8;   //global definitions

void dosomething (int c)   // c is shadowed
{   
	int a = 0;               // a is shadowed
	cout << "dosomething start:\t" << "a= " << a << "   b= " << b << "  c= " << c << endl;
	a = 2 * c - 1;
	c++;
	b++;
	cout << "dosomething end:\t" << "a= " << a << "  b= " << b << "  c= " << c << endl;
}

void dosomething ()   
{
	cout << a << " " << b << " " << c << endl;
	a = 6;
}

int main()
{
	int a = 10; //a is shadowed
	cout << "main start:\t\t" << "a= " << a 
		 << "  b= " << b << "  c= " << c << endl;
	dosomething();
	dosomething();

	dosomething(a);
	c++;
	b++;
	a++;
	cout << "main end:\t\t" << "a= " << a 
		 << "  b= " << b << "  c= " << c << endl;

	return 0;
}
