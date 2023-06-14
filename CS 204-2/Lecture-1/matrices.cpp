//
//  main.cpp
//  Week-1
//
//  Created by Duygu Altop on 30.06.2020.
//  Copyright © 2020 Duygu Altop. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include "prompt.h"
#include "randgen.h"
using namespace std;

int Nrows, Ncols;  // global variables

/* uses local variables for the number of rows/cols */
void printMatrix(const vector<vector<int> > & mat){
    int rows = (int)mat.size();	
    //static int rows = (int)mat.size();	
    //const static int rows = (int)mat.size();	
    if (rows != 0){
        int cols = (int)mat[0].size();
        //static int cols = (int)mat[0].size();
        //const static int cols = (int)mat[0].size();
        for (int i=0; i < rows; i++){
            for (int j=0; j < cols; j++){
                cout << setw(4) << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    //cout << cols << endl;	// syntax error due to scope rules!
}

/* uses global variables for the number of rows/cols */
void printMatrixV2(const vector<vector<int> > & mat){
    if (Nrows != 0){
        for (int i=0; i < Nrows; i++){
            for (int j=0; j < Ncols; j++){
                cout << setw(4) << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
}

/* uses pass by reference variables for the number of rows/cols */
void printMatrix(const vector<vector<int> > & mat, const int & rows, const int & cols){
    if (rows != 0){
        for (int i=0; i < rows; i++){
            for (int j=0; j < cols; j++){
                cout << setw(4) << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
}


void fillMatrix(vector<vector<int> > & mat){
    RandGen r;
    for (int i=0; i < mat.size(); i++){
        for (int j=0; j < mat[0].size(); j++){
            mat[i][j] = r.RandInt(0, 19);
        }
    }
}

/* example on how static variables work */
void func(){
    static int a = 5;
    cout << a << endl;
    a++;
    cout << a << endl;
}

int main() {

	/*
    // example on how static variables work 
    func();
    func();
    func();
    */
    
    /*
    // matrix (vector of vector) construction
    cout << "Empty matrix" << endl;
    vector<vector<int> > mat1;
    printMatrix(mat1);
    cout << "Empty matrix with 3 rows" << endl;
    vector<vector<int> > mat2(3);
    printMatrix(mat2);
    cout << "3x5 matrix, with all values initialized via default int constructor" << endl;
    vector<vector<int> > mat3(3, vector<int>(5));
    printMatrix(mat3);
    cout << "3x5 matrix, with all values initialized to -1" << endl;
    vector<vector<int> > mat4(3, vector<int>(5,-1));
    printMatrix(mat4);
    */

	/* // PromptRange does the same as follows on single line
    int numRows;
    cout << "Please enter the number of rows: ";
    cin >> numRows;
    while (numRows < 2 || numRows > 9){
        cout << "Please enter the number of rows: ";
        cin >> numRows;
    }*/

	/*
  	// get number of rows/cols from user, and fill the matrix randomly
	int numRows = PromptRange("Please enter the number of rows: ", 2, 9);
	int numCols = PromptRange("Please enter the number of columns: ", 2, 9);
	
    vector<vector<int> > mat(numRows, vector<int>(numCols));
    fillMatrix(mat);
    printMatrix(mat);
	cout << "-------" << endl;
	printMatrix(mat, numRows, numCols);
    */

	/*
	// get number of rows/cols from user, and fill the matrix randomly
	// local variable definitions with the same names as that of the global variables
    int Nrows = PromptRange("Please enter the number of rows: ", 2, 9);
    int Ncols = PromptRange("Please enter the number of columns: ", 2, 9);

    vector<vector<int> > mat(Nrows, vector<int>(Ncols));
    fillMatrix(mat);
    printMatrix(mat);				// this one uses local variables for rows/cols
    cout << "-------" << endl;
    printMatrixV2(mat);				// this one uses global variables for rows/cols
    cout << "-------" << endl;
    */
    
	// get number of rows/cols from user, and fill the matrix randomly
	// sets the initial values of the global variables
    Nrows = PromptRange("Please enter the number of rows: ", 2, 9);
    Ncols = PromptRange("Please enter the number of columns: ", 2, 9);

    vector<vector<int> > mat(Nrows, vector<int>(Ncols));
    fillMatrix(mat);
    printMatrix(mat);				// this one uses local variables for rows/cols
    cout << "-------" << endl;
    printMatrixV2(mat);				// this one uses global variables for rows/cols
    cout << "-------" << endl;
    
    return 0;
}
