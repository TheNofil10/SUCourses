#include <iostream>
#include <string>
#include <iomanip>     // for setw
using namespace std;
#include <vector>

//
//// demonstrate class matrix
//
void Print(const vector<vector<int>> & mat)
{
	for (int j = 0; j < mat.size(); j++)
	{
		for (int k = 0; k < mat[0].size(); k++)
		{
			cout << setw(4) << mat[j][k];
		}
		cout << endl;
	}
}

void SumDiagonal(const vector<vector<int>> & mat)
{
	int sumdiag = 0;
	for (int k = 0; k < mat[0].size(); k++)
	{
		sumdiag += mat[k][k];
	}
	cout << "sum of diagonal is " << sumdiag << endl;
}

void SumColumn(const vector<vector<int>> & mat)
{
	for (int j = 0; j < mat[0].size(); j++)
	{
		int sum = 0;
		for (int k = 0; k < mat.size(); k++)
		{
			sum += mat[k][j];
		}
		cout << "sum of column " << j << " is " << sum << endl;
	}
}

//Works with all NxM matrices s.t. N > 3 and M > 3
//When calculating the inner perimeter, we go around in a circle and add each value on the path until next corner, excluding the value of the corner
//numbers indicate which loop add the value to the sum
/*
0 0 0 0 0
0 1 1 2 0
0 4 0 2 0
0 4 3 3 0
0 0 0 0 0
*/
void SumInnerPerimeter(const vector<vector<int>> & mat)
{
	int rows = mat.size();
	int cols = mat[0].size();

	int x = 1, y = 1, sum = 0;


	//right
	while (y < cols - 2)
	{
		sum += mat[x][y];
		y++;
	}
	//down
	while (x < rows - 2)
	{
		sum += mat[x][y];
		x++;
	}
	while (y > 1)
	{
		sum += mat[x][y];
		y--;
	}
	while (x > 1)
	{
		sum += mat[x][y];
		x--;
	}
	cout << "Sum of values on the inner perimeter is " << sum << endl;
}

void SumPath(const vector<vector<int>> & mat)
{
	int row1, col1, row2, col2;
	int rows = mat.size();
	int cols = mat[0].size();

	//Prompt for starting location coordinates until valid
	cout << "Enter coordinates of starting location (row1, col1): ";
	cin >> row1 >> col1;
	while (row1 < 0 || row1 >= rows || col1 < 0 || col1 >= cols)
	{
		cout << "Coordinates out of range!" << endl;
		cout << "Enter coordinates of starting location (row1, col1): ";
		cin >> row1 >> col1;
	}

	//Prompt for ending location coordinates until valid
	cout << "Enter coordinates of starting location (col2, row2): ";
	cin >> row2 >> col2;
	while (row2 < 0 || row2 >= rows || col2 < 0 || col2 >= cols)
	{
		cout << "Coordinates out of range!" << endl;
		cout << "Enter coordinates of ending location (row2, col2): ";
		cin >> row2 >> col2;
	}

	int x = row1, y = col1;
	int sum = mat[x][y]; //start sum as value of starting location
	while (x != row2 || y != col2)
	{
		//first move horizontally until in same column
		if (y != col2)
		{
			if (y < col2)
			{
				y++;
			}
			else
			{
				y--;
			}
		}
		//then move vertically until ending location is reached
		else if (x != row2)
		{
			if (x < row2)
			{
				x++;
			}
			else
			{
				x--;
			}
		}
		//add value of new location
		sum += mat[x][y];
	}

	cout << "Sum of path from (" << row1 << ", " << col1 << ") to (" << row2 << ", " << col2 << ") is " << sum << endl;
}

int main()
{
	int j, k;
	int rows, cols;
	cout << "row col dimensions: ";
	cin >> rows >> cols;
	vector<vector<int>> mat(rows, vector<int>(cols));
	// a vector of vector<int> who has row many elements, which are vector<int>, all 0

	for (j = 0; j < rows; j++)	// fill matrix
	{
		for (k = 0; k < cols; k++)
		{
			mat[j][k] = (j + 1)*(k + 1);
		}
	}

	Print(mat);
	cout << "\n\n";

	SumColumn(mat);

	if (rows == cols)// diagonal only occurs in a square matrix
	{
		cout << "\n";
		SumDiagonal(mat);
	}

	if (rows > 3 && cols > 3)
	{
		SumInnerPerimeter(mat); //perimeter of N-1xN-1 matrix in the middle of given matrix
	}

	SumPath(mat); //sum of values along a path that is determined by user inputs

	//
	// 4 possible matrix declarations
	//
	vector<vector<int>> mat1;   //empty matrix with no rows and columns
	cout << "Printing original mat1" << endl;
	Print(mat1);
	cout << "\n\n";

	//adding elements to mat1
	for (j = 0; j < rows; j++)
	{
		vector<int> temp;  //creating an empty temporary vector
		for (k = 0; k < cols; k++)
		{
			temp.push_back((j + 1)*(k + 1));  // and fill it up
		}
		mat1.push_back(temp);  //then add it as the jth row 
	}

	cout << "Printing mat1 after filling up" << endl;
	Print(mat1);
	cout << "\n\n";


	vector<vector<int>> mat2(rows);  //a matrix with rows amount of rows but all empty
	cout << "Printing original mat2" << endl;
	Print(mat2);
	cout << "\n\n";

	//adding elements to each row
	for (j = 0; j < rows; j++)
	{
		for (k = 0; k < cols; k++)  // fill the jth row
		{
			mat2[j].push_back((j + 1)*(k + 1));
		}
	}
	cout << "Printing mat2 after filling up" << endl;
	Print(mat2);
	cout << "\n\n";

	vector<vector<int>> mat3(rows, vector<int>(cols));  //a matrix with rows rows and cols columns; all zero
	cout << "Printing mat3" << endl;
	Print(mat3);
	cout << "\n\n";

	vector<vector<int>> mat4(rows, vector<int>(cols, -1)); //a matrix with rows rows and cols columns; all -1
	cout << "Printing mat4" << endl;
	Print(mat4);
	cout << "\n\n";


	cout << "\n";
	cin.ignore();
	cin.get();
	return 0;
}
