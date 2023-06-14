#include "SubSeqsList.hpp"
#include <iostream>
using namespace std;

SubSeqsList:: SubSeqsList(){
    hHead=NULL;
}

void SubSeqsList::add_to_end(int x){
    
    SubSeqHeadNode* ptr = hHead;
    if (hHead == NULL){
        SubSeqHeadNode* newPtr = new SubSeqHeadNode(x);
        hHead = newPtr;
    }
    else{
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        SubSeqHeadNode* newPtr = new SubSeqHeadNode(x);
        ptr->next = newPtr;
    }
}

void SubSeqsList::forwardTraversal(){
    
    SubSeqHeadNode* ptr = hHead;
    while (ptr != NULL){
        cout<<ptr->size<<endl;
        ptr = ptr->next;
    }
}

void SubSeqsList::add_between(int x){
    
    SubSeqHeadNode* ptr = hHead;
    while (ptr != NULL){
        if (ptr->next->size > x) {
            break;
        }
        ptr = ptr->next;
    }
    SubSeqHeadNode* newPtr = new SubSeqHeadNode(x);
    newPtr->next = ptr->next;
    ptr->next = newPtr;
}

bool SubSeqsList::findint(int x){
    
    SubSeqHeadNode* ptr1 = hHead;
    while(ptr1 != NULL){
        SubSeqNode* ptr2  = ptr1->sHead;
        while(ptr2 !=  NULL){
            if (ptr2->value == x){
                return true;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return false;
}

bool foundin(SubSeqNode* n ,int x){
    
    while(n != NULL){
        if(n->value == x){
            return true;
        }
        n = n->next;
    }
    return false;
}

void SubSeqsList::deletenode(int x){
    
    SubSeqHeadNode* ptr1 = hHead;
    while(ptr1 != NULL){
        SubSeqNode* ptr2  = ptr1->next->sHead;
        if(foundin(ptr2, x)){
            ptr1->next = ptr1->next->next;
            delete ptr1->next;
            break;
        }
        ptr1 = ptr1->next;
    }
}

void SubSeqsList::deleteall(){
    
    SubSeqHeadNode* ptr1 = hHead;
    while (ptr1  != NULL){
        SubSeqHeadNode* temp = ptr1;
        ptr1 = ptr1->next;
        delete temp;
    }
}
