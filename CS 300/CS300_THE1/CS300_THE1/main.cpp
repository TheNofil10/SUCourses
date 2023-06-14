#include <iostream>
#include <stack>
#include <cstdlib>
#include <vector>
#include "randgen.h"

using namespace std;

struct node {
    bool wallu=true, walld=true, walll=true, wallr=true, visited=false;
    int x, y;
    node*u=NULL;
    node*d=NULL;
    node*l=NULL;
    node*r=NULL;
    
};

vector<vector<node>> gridMaker (int cols, int rows) {
    
    vector<vector<node>> grid(rows, vector<node>(cols));
    
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j<cols; j++) {
            grid[i][j].x = i;
            grid[i][j].y = j;
        }
    }
    return grid;
}

void popstack(stack<node> stack){
    stack.pop();
}

//bool nextpossible(node node){
//    int x = node.x;
//    int y = node.y;
//    if (!node[x+1][y].visited) {
//        return true;
//    }
//    else if (!node[x-1][y].visited){
//        return true;
//    }
//}

int nextwall(){
    RandGen rand;
    int next=rand.RandInt(1,4);
    return next;
}

int main() {
    
    int numOfMazes, rows, cols;
    
#ifndef DEBUG
    cout<<"Enter the number of mazes: ";
    cin>>numOfMazes;
    
    cout<<"Enter the number of rows and columns (M and N): ";
    cin>>rows>>cols;
#else
    numOfMazes=5;
    rows=4;
    cols=6;
    cout<<numOfMazes<<endl<<rows<<endl<<cols<<endl;
#endif
        
    bool done=false;
    
    vector<vector<node>>grid=gridMaker(rows, cols);
    
    stack<node> myStack;

    myStack.push(grid[0][0]);
    
    
    
    while (myStack.size()!=0) {
        node currentCell=myStack.top();
        
    }
}
