#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//void printseries(){
//
//}
//
//void searchrating(){
//
//}
//
//void addtofav(){
//
//}
//
//void printfav(){
//
//}
//struct series{
//    string name, cast;
//    double rating;

int main(){
    
    ifstream inputactor, inputrating;
    string actorfile, ratingfile, actorline, ratingline, word, title, actorname;
    double movierating, digit;
    int len, s;
    
    cout<<"Welcome to Netflix TV Series Ratings Calculator!"<<endl;
    cout<<"Please enter a filename for Series-Actor file: ";
    cin>>actorfile;
    actorfile="actors_series.txt";//temp-----------------------------------------
    inputactor.open(actorfile.c_str());
    
    while (inputactor.fail()){
        cout<<"Can not find the specified file."<<endl;
        cout<<"Please enter a filename for Series-Actor file: ";
        cin>>actorfile;
        inputactor.open(actorfile.c_str());
        
    }
    cout<<"Please enter a filename for Rating file: ";
    cin>>ratingfile;
    ratingfile="ratings.txt";//temp-----------------------------------------------
    inputrating.open(ratingfile.c_str());
    
    while (inputrating.fail()){
        cout<<"Can not find the specified file."<<endl;
        cout<<"Please enter a filename for Rating file: ";
        cin>>ratingfile;
        inputrating.open(ratingfile.c_str());
    }
    
    vector<int> ratings;
    vector<string> actornames;
    vector<string> seriesnames;
    
    while (getline(inputrating, ratingline)) {
        string seriesname="";
        istringstream x(ratingline);
        int i=0;
        while (x>>word) {
            if (i>0) {
                seriesname=seriesname+word+" ";
            }
            seriesnames.push_back(seriesname);
            i++;
        }
        len=seriesname.length();
        seriesname.erase(len-1);
        
        istringstream y(ratingline);
        while (y>>digit) {
            movierating=digit;
            ratings.push_back(movierating);
        }
    }
    while (getline(inputactor,actorline)) {
        s=actorline.find(";");
        actorname=actorline.substr(0,s);
        title=actorline.substr(s+2);
    }
    
    int n=0;
    while(n<seriesnames.size())
    {
        cout<<seriesnames[n]<<" "<<ratings[n]<<endl;
    }
    
    
    return 0;
}


