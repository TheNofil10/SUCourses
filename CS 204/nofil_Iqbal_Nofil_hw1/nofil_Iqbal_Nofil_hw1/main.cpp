#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

//bool checkInput(string input){
//
//}

int main() {
    
    ifstream inFile;
    string filename, currentInput, inLine, word, direction, rotation;
    int row, col, x, y;
    
    cout<<"Please enter the name of the file: ";
    cin>>filename;
    
    inFile.open(filename.c_str());
    
    while (inFile.fail()){
        cout<<"File name is incorrect, please enter again: ";
        cin>>filename;
        inFile.open(filename.c_str());
    }
    
    inFile>>row>>col;
    
    vector<vector<char>> matrix(row, vector <char>(col,'-'));
    
//    for (int j=0; j<matrix.size(); j++) {
//        for (int k=0; k<matrix[0].size(); k++) {
//            cout<<matrix[j][k];
//        }
//        cout<<endl;
//    }
    int line=1;
    
    while (!inFile.eof()) {
        while (getline (inFile,inLine)) {
            if (line!=1) {
                cout<<inLine<<endl;
                istringstream stream(inLine);
                stream>>word>>x>>y>>direction>>rotation;
//                cout<<"word is "<<word<<endl;
//                cout<<"starting points are "<<x<<", "<<y<<endl;
//                cout<<"direction is "<<direction<<endl;
//                cout<<"rotation is "<<rotation<<endl;
                
                
                
            }
            line++;
        }
    }

    
    
    return 0;
}
