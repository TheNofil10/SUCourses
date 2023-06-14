#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
//#include "HashTable.h"
//#include "BST.h"

using namespace std;

int main() {
    
    int numFiles;
    vector<string> fileNames;
    
    cout<<"Enter number of input files: ";
    cin>>numFiles;
    
    for (int i = 1; i <= numFiles; i++) {
        
        string filename;
        
        cout<<"Enter " << i << ". file name: ";
        cin>>filename;
        fileNames.push_back(filename);
    }

//    HashTable<string> table;
//    
//    //BinarySearchTree<string> bst();
//    
//    for (int i = 0; i < fileNames.size(); i++) {
//        string word, tempFile = fileNames[i];
//        
//        ifstream file;
//        file.open(tempFile);
//        
//        while (getline(file, word)) {
//            table.insert(word, tempFile);
//        }
//    }
//    cout<<table.printRehash();

    
    return 0;
}
