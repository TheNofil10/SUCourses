#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include "SubSeqsList.hpp"
using namespace std;

int main() {
    
    string num;

    cout<<"Please enter the numbers in a line: ";

    getline(cin, num);

    //output when enter is pressed without any numbers
    if (num=="") {
        cout<<"FINAL CONTENT"<<endl<<"List is empty!"<<endl;
        return 0;
    }

    istringstream line(num);

    int s;

    while (line>>s) {
        
        
        
    }
    
    
    return 0;
}
