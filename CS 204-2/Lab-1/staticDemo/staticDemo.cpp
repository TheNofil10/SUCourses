#include <iostream>
using namespace std;

int thefunction(int a)
{
	static int b = 0;
	b++;
	a = a + b;
	return a;
}

int main()
{
	int b = 0;
	int i;
	for(i = 1; i <= 3; i++)
	{
		b += thefunction(i);
	}
	cout << b << endl;
	return 0;
}