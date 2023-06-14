//
//  main.cpp
//  nofil_Iqbal_Nofil_hw4
//
//  Created by Nofil Iqbal on 08/04/2021.
//

#include <iostream>
#include <fstream>
#include "Stack.h"

using namespace std;

struct cellstruct
{
    bool flag;
    char ch;
    
};

void Print(Stack& myStack,string str)       //To print out the complete Stack
{
    
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"The bit string "<<str<<" is found following these cells:"<<endl;

    Stack reverseStack;
    int int1,int2;
    
    while(!myStack.isEmpty()){      //To reversing the stack
        myStack.pop(int1,int2);
        reverseStack.push(int1,int2);
    }
    
    while(!reverseStack.isEmpty()){     //To print out the reversed stack
        reverseStack.pop(int1,int2);
        cout << "("<<int1<<","<<int2<<")" << " ";
    }
    cout<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    
}

void DeleteMatrix(cellstruct ** mat, int size){   //function to delete the matrix
    
    for(int i=0; i<size; i++)
    {
        delete [] mat[i];
    }
    delete [] mat;
}



int main(){
    int row, col;
    int currCol = 0;
    int currRow=0;
    string filename,lines;
    char num;
    bool complete = false;
    ifstream inputFile;
    cout << "Please enter the number of rows: ";
    cin>> row;
    cout<<"Please enter the number of columns: ";
    cin>> col;

    cout<<"Please enter the name of the input file that contains the matrix: ";
    cin >>filename;
    
    inputFile.open(filename.c_str());
    while (inputFile.fail()) {  //Taking filename until valid
        cout<<"File cannot be opened."<<endl;
        cout<<"Please enter the name of the input file that contains the matrix: ";
        cin >>filename;
        inputFile.open(filename.c_str());
    }
    
    
    cellstruct** ptrmatrix = new cellstruct*[row];    //creating matrix
    for(int i =0; i<row; i++)
    {
        ptrmatrix[i] = new cellstruct[col];
    }
    
    while(inputFile.get(num)){
        if(num == '0' || num == '1'){ //to process input from input file
            ptrmatrix[currRow][currCol].ch = num;
            ptrmatrix[currRow][currCol].flag = false;
            currCol ++;
        }
        else{
            currCol = 0;
            currRow++;
        }
    }

    string input;
    cout<<"Please enter a string of bits to search (CTRL+Z to quit): ";
    cin >> input;

    Stack CellStructStack; //calling stack constructor
    while(!cin.eof()){ //for ctrl-z function
//        cout<<"origin is :"<<ptrmatrix[0][0].ch;
        if(ptrmatrix[0][0].ch != input[0]){
            ptrmatrix[0][0].flag = true;
        }
        int matr = 0;
        int matc = 0;
        int strCount = 0;  //for index of input
        while(complete != true && ptrmatrix[0][0].flag != true){
            if(ptrmatrix[matr][matc].flag == false && ptrmatrix[matr][matc].ch == input[strCount]){
                CellStructStack.push(matr,matc);
                if(strCount < (input.size()-1)){
                    strCount++;
                    if(!ptrmatrix[matr][matc+1].flag){
                        //if we can go right
                        if(ptrmatrix[matr][matc+1].ch == input[strCount]){
                            matc++;
                        }
                        else{
                            ptrmatrix[matr][matc+1].flag = true;
                        }
                    }
                    else if(!ptrmatrix[matr+1][matc].flag) {
                        // if we can go down
                        if(ptrmatrix[matr+1][matc].ch == input[strCount]){
                            matr++;
                        }
                        else{
                           ptrmatrix[matr+1][matc].flag = true;
                        }
                    }
                    else if(!ptrmatrix[matr+1][matc].flag && !ptrmatrix[matr][matc+1].flag && ptrmatrix[matr+1][matc].ch != input[strCount] && ptrmatrix[matr][matc+1].ch != input[strCount]){
                        //if stuck
                        ptrmatrix[matr][matc].flag = true;
                    }
                    else if(ptrmatrix[matr+1][matc].flag && ptrmatrix[matr][matc+1].flag){
                        //if stuck
                        ptrmatrix[matr][matc].flag = true;
                    }
                }
                else{
                    //if the pattern is found
                    complete = true;
                    //break;
                }
            }
            else if((ptrmatrix[matr][matc].flag || ptrmatrix[matr][matc].ch != input[strCount])){
                //go back if no other place is possible
                 ptrmatrix[matr][matc].flag = true;
                 CellStructStack.pop(matr,matc);
                 strCount--;
            }
        }
        if(complete && !ptrmatrix[0][0].flag){
            //if pattern hsa been found
            Print(CellStructStack,input);
            complete = false;
//            for(int i=0; i<row; i++) //reseting all the flag values to false for searching again
//            {
//                for(int j=0; j<col; j++)
//                {
//                     ptrmatrix[i][j].flag = false ;
//                }
//            }
        }
        else{
            cout<<"The bit string " << input<< " could not be found."<< endl;
            cout<<"---------------------------------------------------------"<<endl;
            
        }
        for(int i=0; i<row; i++) //reseting all the flag values to false for searching again
        {
            for(int j=0; j<col; j++)
            {
                 ptrmatrix[i][j].flag = false ;
            }
        }
        cin.ignore();
        cin.clear();
        cout<<"Please enter a string of bits to search (CTRL+Z to quit): ";
        cin >> input;
    }
    DeleteMatrix(ptrmatrix,row);
    cout<<"Program ended successfully!"<<endl;
    cout<<endl;

return 0;
}
