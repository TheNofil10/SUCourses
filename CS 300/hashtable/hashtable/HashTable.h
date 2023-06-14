#include <vector>
#include <iostream>

using namespace std;

//class copied from lecture slides

struct DocumentItem {
    string documentName;
    int count;
    
    DocumentItem() :
        documentName(""), count(0) {}

    DocumentItem(string p = "",  int t = 0) : documentName(p), count(t)
    {
    }
};

vector<DocumentItem> doc;

struct WordItem {
    string word;
    vector<DocumentItem> vect;
    //vector<DocumentItem> doc;
    //doc.push_back();
    
    
    WordItem(string p = "",  vector<DocumentItem> t =  ::doc) : word(p), vect(t)
    {
    }
};

template <class HashedObj>
class HashTable
{
public:
    explicit HashTable(const HashedObj& notFound, int size = 101);
    HashTable(const HashTable& rhs)
        : ITEM_NOT_FOUND(rhs.ITEM_NOT_FOUND),
        array(rhs.array), currentSize(rhs.currentSize) { }

    const HashedObj& find(const HashedObj& x) const;
    
    HashTable(){}
    
    void makeEmpty();
    void insert(const HashedObj& x, const string fileName);
    //void insert1(const WordItem x, const string fileName);
    void remove(const HashedObj& x);
    const HashTable& operator=(const HashTable& rhs);
    
    void printRehash();

    
    
    struct DocumentItem {
         string documentName;
    int count; };
    struct WordItem {
         string word;
         // List of DocumentItem’s.
    };

private:
    struct HashEntry
    {
        WordItem element;
        string info;
        //WordItem j;
        

        HashEntry(const WordItem e = WordItem(), string i = string())
            : element(e), info(i) { }
    };

    vector<HashEntry> array;
    int prevtb = array.size();
    int newtb;
    int currwordcount;
    int loadratio;
    int currentSize;
    const HashedObj ITEM_NOT_FOUND;

    bool isActive(int currentPos) const;
    int findPos(const HashedObj& x) const;
    void rehash(const string fileName);
    int hashing(const HashedObj & x, int totalsize) const{ // x mod M
        return 0;
    };
};


int nextPrime(int n);
bool isPrime(int n);

template <class HashedObj>
HashTable<HashedObj>::HashTable(const HashedObj& notFound, int size)
	: ITEM_NOT_FOUND(notFound), array(nextPrime(size))
{
	makeEmpty();
}

template <class HashedObj>
void HashTable<HashedObj>::makeEmpty()
{
	currentSize = 0;
    prevtb = 0;
    currwordcount=0;
    newtb = 0;
    loadratio = 0;
}

template <class HashedObj>
int HashTable<HashedObj>::findPos(const HashedObj& x) const
{
	int collisionNum = 0;
	int currentPos = hashing(x, array.size());
    
    cout<<array[currentPos].info<<endl;

	while (array[currentPos].info != "EMPTY" && array[currentPos].element.word != x)
        
	{
		currentPos += 2 * ++collisionNum - 1;  
		if (currentPos >= array.size())             
			currentPos -= array.size();             
	}

	return currentPos;
}

template <class HashedObj>
bool HashTable<HashedObj>::isActive(int currentPos) const
{
	return array[currentPos].info == "ACTIVE";
}

template <class HashedObj>
void HashTable<HashedObj>::remove(const HashedObj& x)
{
	int currentPos = findPos(x);
	if (isActive(currentPos))
		array[currentPos].info = "DELETED";
}


template <class HashedObj>
const HashedObj& HashTable<HashedObj>::find(const HashedObj& x)const
{
	int currentPos = findPos(x);
	if (isActive(currentPos))
		return array[currentPos].element;

	return   ITEM_NOT_FOUND;
}

template <class HashedObj>
void HashTable<HashedObj>::insert(const HashedObj& x, const string fileName)
{
    WordItem temp;
    temp.word = x;
	int currentPos = findPos(x);
    if (isActive(currentPos)&& array[currentPos].element.word == x){
        vector <DocumentItem> temp;
        //temp = array[currentPos].element.;

        bool found = false;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i].documentName == fileName) {
                found = true;
                temp[i].count++;
            }
        }
        if (!found) {
            DocumentItem fal;
            fal.count = 1;
            fal.documentName = fileName;
            temp.push_back(fal);
            //array[currentPos].element.vect = temp;
            currwordcount++;
        }
    }
    
	array[currentPos] = HashEntry(temp, "ACTIVE");
    
    loadratio = currwordcount/array.size();

	 
	if (loadratio >= 0.9)
		rehash(fileName);
}
/*
template <class HashedObj>
void HashTable<HashedObj>::insert1(const string x, const string fileName)
{
    WordItem temp;
    temp.word = x;
    int currentPos = findPos(x);
    if (isActive(currentPos)&& array[currentPos].element.word == x){
        vector <DocumentItem> temp;
        //temp = array[currentPos].element.;

        bool found = false;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i].documentName == fileName) {
                found = true;
                temp[i].count++;
            }
        }
        if (!found) {
            DocumentItem fal;
            fal.count = 1;
            fal.documentName = fileName;
            temp.push_back(fal);
            //array[currentPos].element.vect = temp;
            currwordcount++;
        }
    }
    
    array[currentPos] = HashEntry(temp, ACTIVE);
    
    loadratio = currwordcount/array.size();

     
    if (loadratio >= 0.9)
        rehash(fileName);
}
 */

template <class HashedObj>
void HashTable<HashedObj>::rehash(const string fileName)
{
	vector<HashEntry> oldArray = array;

    prevtb = array.size();
	
	array.resize(nextPrime(2 * oldArray.size()));
	for (int j = 0; j < array.size(); j++)
		array[j].info = "EMPTY";

	
	currentSize = 0;
    for (int i = 0; i < oldArray.size(); i++){
        if (oldArray[i].info == "ACTIVE"){
            insert(oldArray[i].element.word, fileName);
        }
    }
    newtb = array.size();
    
    printRehash();
}

template <class HashedObj>
void HashTable<HashedObj>::printRehash(){
    cout << "rehashed..." << endl;
    cout << "previous table size:" << prevtb << ", new table size: " << newtb << ", current unique word count " << currwordcount << ", current load factor: " << loadratio << endl;
}

int nextPrime(int n) {
	if (n % 2 == 0)
		n++;

	for (; !isPrime(n); n += 2)
		;

	return n;
}

bool isPrime(int n) {
	if (n == 2 || n == 3)
		return true;

	if (n == 1 || n % 2 == 0)
		return false;

	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;

	return true;
}



#pragma once
