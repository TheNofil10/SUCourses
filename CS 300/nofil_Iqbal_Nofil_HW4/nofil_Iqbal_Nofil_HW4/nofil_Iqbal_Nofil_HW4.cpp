// Nofil Iqbal 28631

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <chrono>
#include <string>
#include <cctype>

using namespace std;
using namespace std::chrono;

struct info{
    string name, num, address;
};

void printVec(vector <info> & a){
    for (int i = 0; i<a.size(); i++) {
            cout<<a[i].name<<" "<<a[i].num<<" "<<a[i].address<<endl;
        }
}

string uppercase(string word){
    for (int i = 0; i<word.size(); i++) {
        word[i] = toupper(word[i]);
    }
    return word;
}

//----------------------------INSERTION SORT-----------------------------------------------------

template <class T> void insertionSort (vector <T> & a)
{
    int j;
    for (int p = 1;  p < a.size(); p++)
    {
        T tmp = a[p];
        for (j = p; j > 0 &&  tmp.name < a[j-1].name; j--){
            a[j] = a[j-1];
        }
        a[j] = tmp;
    }
}
//----------------------------INSERTION SORT-----------------------------------------------------


//----------------------------QUICK SORT-----------------------------------------------------


template <class T> int partition(vector<T>& list, int first, int last) {
    // The pivot should be the median of the
    // first, middle, and last elements.
    int middle = first + (last - first) / 2;

    if (list[first].name > list[middle].name)
        swap(list[first], list[middle]);

    if (list[first].name > list[last].name)
        swap(list[first], list[last]);

    if (list[middle].name > list[last].name)
        swap(list[middle], list[last]);

    swap(list[middle], list[first]);

    T pivot = list[first];
    int i = first - 1;
    int j = last + 1;

    while(true) {
        do {
            i++;
        } while(list[i].name < pivot.name);

        do {
            j--;
        } while(list[j].name > pivot.name);

        if(i >= j)
            return j;

        swap(list[i], list[j]);
    }
}

template <class T> void quickSort(vector<T>& list, int first, int last) {
    if(first < last) {
        int pivotLocation = partition(list, first, last);
        quickSort(list, first, pivotLocation);
        quickSort(list, pivotLocation + 1, last);
    }
}

//----------------------------QUICK SORT-----------------------------------------------------

//----------------------------MERGE SORT-----------------------------------------------------

template <class T>
void MergeSortedIntervals(vector<T>& v, int s, int m, int e) {
    
    // temp is used to temporary store the vector obtained by merging
    // elements from [s to m] and [m+1 to e] in v
    vector<T> temp;

    int i, j;
    i = s;
    j = m + 1;

    while (i <= m && j <= e) {

        if (v[i].name <= v[j].name) {
            temp.push_back(v[i]);
            ++i;
        }
        else {
            temp.push_back(v[j]);
            ++j;
        }

    }

    while (i <= m) {
        temp.push_back(v[i]);
        ++i;
    }

    while (j <= e) {
        temp.push_back(v[j]);
        ++j;
    }

    for (int i = s; i <= e; ++i)
        v[i] = temp[i - s];

}

// the MergeSort function
// Sorts the array in the range [s to e] in v using
// merge sort algorithm

template <class T>
void mergeSort(vector<T>& v, int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        MergeSortedIntervals(v, s, m, e);
    }
}



//----------------------------MERGE SORT-----------------------------------------------------

//----------------------------HEAP SORT-----------------------------------------------------

inline int leftChild( int i )
{
    return 2*i+1;
}


template <class Comparable>
void heapSort(vector<Comparable> & a)
{
    // buildHeap
    for (int i = a.size()/2; i >=0; i--){
        percDown(a, i, a.size());
    }

    // sort
    for (int j = a.size() -1; j > 0; j--)
    {
           swap(a[0], a[j]);    // swap max to the last pos.
          percDown(a, 0, j); // re-form the heap
    }
}

template <class Comparable>  // for deleteMax
        // a is the array, i is the position to percolate down from
        // n is the logical size of the array
        void percDown( vector<Comparable> & a, int i, int n )
        {
                int child;
                Comparable tmp;

                for (tmp=a[i] ; leftChild(i) < n; i = child )
                {
                     child = leftChild(i);
                     if ( child != n-1 && a[ child  ].name < a[ child+1 ].name )
                          child++;
                     if ( a[child ].name > tmp.name )
                          a[i] = a[ child ];
                     else
                          break;
               }
               a[ i ] = tmp;
        }


//----------------------------HEAP SORT-----------------------------------------------------

//----------------------------SEQUENTIAL SEARCH-----------------------------------------------------

template <class T>
vector<T> sequentialSearch(vector<T> a, string x)
{
    vector<T> temp;
    for (int i = 0; i < a.size(); i++)
        if (a[i].name.find(x) != string::npos)
            temp.push_back(a[i]);
    return temp;
}

//----------------------------SEQUENTIAL SEARCH-----------------------------------------------------

//----------------------------BINARY SEARCH-----------------------------------------------------

template <class T>
vector<T> binarySearch(const vector<T>& sorted_vec, string key) {
    
    vector<T> temp;
    
    int mid, left = 0 ;
    int right = sorted_vec.size(); // one position passed the right end
    while (left < right) {
       mid = left + (right - left)/2;
       if (key > sorted_vec[mid].name){
           left = mid+1;
       }
       else if (key < sorted_vec[mid].name){
         right = mid;
       }
       else {
           temp.push_back(sorted_vec[mid]);
           mid++;
      }
    }
    return temp;
}

//----------------------------BINARY SEARCH-----------------------------------------------------

int main() {//******************************************************************************************************************************MAIN
    
    string bookname, line, searchWord;
    vector<info> insertionVec;
    vector<info> quickVec;
    vector<info> mergeVec;
    vector<info> heapVec;
    
    cout<<"Please enter the contact file name:"<<endl;      //----------RELAEASE-------------------------------------------------------------------
    cin>>bookname;                                          //----------RELAEASE-------------------------------------------------------------------
    
    cout<<"Please enter the word to be queried :"<<endl;    //----------RELAEASE--------------------------------------------------------------------
    cin>>searchWord;    //----------RELAEASE----------------------------------------------------------------------
    searchWord = uppercase(searchWord);
    
//    bookname = "PhoneBook-sample1.txt";     //----------DEBUG---------------------------------------------------------------------------
//    searchWord = "Ashley";     //----------DEBUG---------------------------------------------------------------------------
    
    cout<<endl;
    cout<<"Sorting the vector copies"<<endl;
    cout<<"======================================"<<endl;
    
    ifstream file;
    file.open(bookname);
    
    while (getline(file, line)) {
        info temp;
        string name, surname, num, address, fullname;
        
        stringstream ss(line);
        while (ss>>name>>surname>>num>>address){
            fullname = name + " " + surname;
            temp.name = uppercase(fullname);
            temp.num = num;
            temp.address = address;
        }
        insertionVec.push_back(temp);
        quickVec.push_back(temp);
        mergeVec.push_back(temp);
        heapVec.push_back(temp);
    }
    
    
    //----------------------------QUICK SORT-----------------------------------------------------
    int N = 100; // if cannot be measured, try N = 1000
    auto start2 = high_resolution_clock::now();  // start measuring
    for (int i = 0; i < N; i++){
        quickSort(quickVec, 0, quickVec.size()-1);
    }
    auto stop2 = high_resolution_clock::now();   // end measuring
    auto quickTime = (duration_cast<nanoseconds>(stop2 - start2)) / N;
    
    cout<<"Quick Sort Time: "<<quickTime.count()<<" Nanoseconds"<<endl;
    
    
    
    //----------------------------INSERTION SORT-----------------------------------------------------
    
    auto start = high_resolution_clock::now();  // start measuring
    for (int i = 0; i < N; i++){
        insertionSort(insertionVec);
    }
    auto stop = high_resolution_clock::now();   // end measuring
    auto insertionTime = (duration_cast<nanoseconds>(stop - start)) / N;
    
    cout<<"Insertion Sort Time: "<<insertionTime.count()<<" Nanoseconds"<<endl;
    
    
    //----------------------------MERGE SORT-----------------------------------------------------

    auto start3 = high_resolution_clock::now();  // start measuring
    for (int i = 0; i < N; i++){
        vector<info> temp;
        mergeSort(mergeVec, 0, mergeVec.size()-1);
    }
    auto stop3 = high_resolution_clock::now();   // end measuring
    auto mergeTime = (duration_cast<nanoseconds>(stop3 - start3)) / N;
    
    cout<<"Merge Sort Time: "<<mergeTime.count()<<" Nanoseconds"<<endl;
    
    
    //----------------------------HEAP SORT-----------------------------------------------------

    auto start4 = high_resolution_clock::now();  // start measuring
    for (int i = 0; i < N; i++){
        vector<info> temp;
        heapSort(heapVec);
    }
    auto stop4 = high_resolution_clock::now();   // end measuring
    auto heapTime = (duration_cast<nanoseconds>(stop4 - start4)) / N;
    
    cout<<"Heap Sort Time: "<<heapTime.count()<<" Nanoseconds"<<endl<<endl;
    
    cout<<"Searching for "<<searchWord<<endl;
    cout<<"======================================"<<endl;
    
    //----------------------------BINARY SEARCH-----------------------------------------------------
    
//    vector<info> binaryVec;
//
//    auto start5 = high_resolution_clock::now();  // start measuring
//    for (int i = 0; i < N; i++){
//        vector<info> binaryFinal;
//        binaryVec = binarySearch(heapVec, searchWord);
//    }
//    auto stop5 = high_resolution_clock::now();   // end measuring
//    auto binaryTime = (duration_cast<nanoseconds>(stop5 - start5)) / N;
//
//    printVec(binaryVec);
    
    //----------------------------SEQUENTIAL SEARCH-----------------------------------------------------
    
    vector<info> seqVec;
    
    auto start6 = high_resolution_clock::now();  // start measuring
    for (int i = 0; i < N; i++){
        seqVec = sequentialSearch(heapVec, searchWord);
    }
    auto stop6 = high_resolution_clock::now();   // end measuring
    auto seqTime = (duration_cast<nanoseconds>(stop6 - start6)) / N;
    
    cout<<"Search results for Sequential Search:"<<endl;
    
    if (seqVec.size() > 0) {
        printVec(seqVec);
    }
    else {
        cout<<searchWord<<"  does NOT exist in the dataset"<<endl<<endl;
    }
    
    cout<<"Sequential Search Time: "<<seqTime.count()<<" Nanoseconds"<<endl<<endl;
    
    
    cout<<"SpeedUps between Sorting Algorithms"<<endl;
    cout<<"======================================"<<endl;
    
    float x = insertionTime.count();
    float y = quickTime.count();
    float z = mergeTime.count();
    float q = heapTime.count();
    
    float insquick = x/y;
    float mergequick = z/y;
    float heapquick = q/y;
    
    
    cout<<"(Insertion Sort/ Quick Sort) SpeedUp = "<<setprecision(6)<<insquick<<endl;
    cout<<"(Merge Sort / Quick Sort) SpeedUp = "<<setprecision(6)<<mergequick<<endl;
    cout<<"(Heap Sort / Quick Sort) SpeedUp = "<<setprecision(6)<<heapquick<<endl;
    
    
    return 0;
}
