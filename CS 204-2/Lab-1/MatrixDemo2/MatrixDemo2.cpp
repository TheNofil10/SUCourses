#include <iostream>
#include <string>
#include<sstream>
#include<fstream>
#include <iomanip>     // for setw
#include <vector>

using namespace std;

void Print(   ){

	// To be filled in during the lab...
}

void SumDiagonal(  ){
	// To be filled in during the lab...
}

void SumColumn(  ){
	// To be filled in during the lab...
}

void SumDiagonalReverse(  ){
	// To be filled in during the lab...
}

int sumSubvector(     ){
	// To be filled in during the lab...
}

void printSubvector(    ){
	// To be filled in during the lab...
}

int main(){
	
	// Input a filename from the user, open the file and read the data into a matrix
	
	
	
	Print(   );
	cout << "\n\n";

	SumColumn(   );

	if (     ){		// diagonal only occurs in a square matrix
		cout << "\n";
		SumDiagonal(   );
		cout << "\n";
		SumDiagonalReverse(   );
	}

	int rowNumber, subvectorLength;
	cout << "Enter the row number to search" << endl;
	cin >> rowNumber;
	cout << "Enter the length of the subvector" << endl;
	cin >> subvectorLength;

	int sumOfVector = 0;

	for(int i = 0; i <  ; i++) {
		sumOfVector = sumSubvector(   );
		printSubvector(   );
		cout << " sums to : " << sumOfVector << endl;
	}

	cout << "end of execution.\n";
	
	return 0;  

}