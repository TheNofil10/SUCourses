#ifndef _LINKSTRINGSET_H
#define _LINKSTRINGEST_H

#include <string>
using namespace std;

//#define UPDATELIST  //define UPDATELIST if you want to update the info field of a node using the iterator class

class LinkStringSet {
  public:
    LinkStringSet(void);
    
    // methods for deep copy
    LinkStringSet(const LinkStringSet& set);
    const LinkStringSet& operator =(const LinkStringSet& set);
    ~LinkStringSet(void);
    
    // accessors
    
    bool contains(const string& s) const;  // true iff s in set
    int  size(void)                const;  // # elements in set
    
    // mutators
    
    void insert(const string& s);  // add to set
    void erase(const string& s);   // remove from set
    void clear(void);              // delete all elements
    
    friend class LinkStringSetIterator;
    
  private:
  
    struct Node {
        string info;
        Node * next;
        Node(const string& s, Node * link) : info(s), next(link) { }
    };
    
    Node * findNode(const string& s) const;  // helper
    void   reclaimNodes(Node * ptr);         // delete/reclaim
    Node * clone(void) const;                // copy list
    
    Node * myFirst;
    int    mySize;
};



/************************************************************************/
class LinkStringSetIterator {
  public:
    LinkStringSetIterator(const LinkStringSet& lset) : mySet(lset), myCurrent(0) {}
     
    void Init(void) {
         myCurrent = mySet.myFirst->next;  // first node
    }
    bool HasMore(void) const {
        return myCurrent != 0;
    }

#ifndef UPDATELIST
	 //returns a copy of myCurrent->info - not good if info will be updated
    string Current(void) const {
        return myCurrent->info;
    }
#endif

#ifdef UPDATELIST
	 //returns reference to myCurrent->info - good if info will be updated
    string & Current(void) const {
        return myCurrent->info;
    }
#endif

    void Next(void) {
        myCurrent = myCurrent->next;
    }

  private:
    typedef LinkStringSet::Node Node;
    const LinkStringSet& mySet;
    Node* myCurrent;
};

#endif
