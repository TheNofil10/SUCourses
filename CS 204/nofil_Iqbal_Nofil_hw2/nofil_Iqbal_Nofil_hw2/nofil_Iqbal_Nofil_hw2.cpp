//
//  main.cpp
//  nofil_Iqbal_Nofil_hw2
//
//  Created by Nofil Iqbal
//

#include <iostream>
#include <sstream>
using namespace std;

struct node
{
    int value;
    node* next;

    node()
        :value(0), next(NULL)
    {}
    //DEFAULT CONSTRUCTOR

    node (int i,node *n)
        :value(i), next(n)
    {}
    //CONSTRUCTOR
    
};



int main() {
    
    string order, numbers;
    
    cout<<"Please enter the order mode (A/D): ";
    cin>>order;
    
    while (order != "A" && order != "D") {
        cout<<"Please enter the order mode again (A/D): ";
        cin>>order;
    }
    
    cout<<"Please enter the numbers in a line: ";
    getline(cin, numbers);
    stringstream num(numbers);
    
    
    
    return 0;
}
