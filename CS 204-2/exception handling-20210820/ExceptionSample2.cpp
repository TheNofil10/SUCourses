#include <iostream>
#include <string>
using namespace std;

int ToInches (int cm){
	return cm/2.54;
}

int main(){
	int height;
	cin >> height;
	try{
		if (height <= -1)
			throw 0;  // change 0 to a real number (e.g. 0.5) and see that the exception will not be caught
		if (height > 300)
			throw "height exceeds maximum";
		if (height < 30)
			throw "height below minimum";
		cout << "Person is " << ToInches(height) << " inches tall" << endl;
	}
	catch(const char msg[]){
		cout << "Exception occured: " << msg << endl;
	}
	catch (int i){
		cout << "Bad input: height cannot be less than " << i << endl;
	}

	cout << "Program Stops " << endl;

	return 0;
}
