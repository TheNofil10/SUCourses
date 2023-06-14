#ifndef SubSeqsList_hpp
#define SubSeqsList_hpp

#include <stdio.h>
#include <string>
using namespace std;

struct SubSeqNode
{
    int value;
    SubSeqNode * next;
    
    //constructors come here
    SubSeqNode(int x = 0, SubSeqNode* n = NULL)
    : value(x), next(n) {}
};

struct SubSeqHeadNode
{
    int size;   // number of elements in the subsequence
    SubSeqNode* sHead;  //head of the subsequent list
    SubSeqHeadNode* next;
    
    //constructors come here
    SubSeqHeadNode(int x = 0, SubSeqNode* n = NULL, SubSeqHeadNode* N = NULL)
    : size(x), sHead(n), next(N) {}
};

class SubSeqsList
{
public:
    SubSeqsList (); //default constructor that creates an empty  list
    //member functions come here
    
    void add_to_end(int);   //adds value to end of list
    void add_between(int);  //adds value between list in ascending order
    void forwardTraversal();    //prints list in acending order
    bool findint(int);  //checks if a specific integer already exists in the list or not
    void deletenode(int);   //deletes the head hode
    void deleteall();   //deletes complete list
    
    
private:
    SubSeqHeadNode* hHead;
    //any helper functions you see necessary
        
};




#endif /* SubSeqsList_hpp */
