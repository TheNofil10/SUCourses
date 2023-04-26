#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype>
#include "strutils.h"
#include "favoriteseries.h"
#include "date.h"

using namespace std;

void printmenu() {
    
    cout<<"---"<<endl<<"MENU"<<endl<<"1. Print all TV series"<<endl<<"2. Add TV series"<<endl<<"3. Drop TV series"<<endl<<"4. Print your favorite series with schedule"<<endl<<"5. Print all your favorite actors"<<endl<<"6. Exit"<<endl<<"---"<<endl<<"Please enter your choice: ";
}

//void choice1()  {
//
//}
//
//void choice2()  {
//
//}
//
//void choice3()  {
//
//}
//
//void choice4()  {
//
//}
//
//void choice5()  {
//
//}


int main() {

    int choice, number;
    string name, surname, fullname, seriesline, epiline, word, d, m, y;
    ifstream seriesfile, epifile;
    vector<series> seriesvector(9999);

    seriesfile.open("series.txt");
    epifile.open("episodes.txt");
    string tempname;
    string actor;
    int i=0;

    while (getline(seriesfile, seriesline)) {

        istringstream x(seriesline);

        bool namedone=false;
        while (x>>word) {

            string b;
            b=word.back();
            number=atoi(word);
            if (number!=0) {
                seriesvector[i].seriesCode=number;
            }
            else if (!namedone){
                if (b!=";") {
                    tempname=tempname+" "+word;
                }
                else if(b==";") {
                    tempname=tempname+" "+word;
                    namedone=true;
                    tempname.erase(0,1);
                    tempname.erase(tempname.length()-1);
                    seriesvector[i].seriesName=UpperString(tempname);
                    tempname.clear();
                }
            }
            else if (namedone==true){
                if (b!=",") {
                    actor=actor+" "+word;
                }
                else if (b==",") {
                    actor=actor+" "+word;
                    actor.erase(0,1);
                    actor.erase(actor.length()-1);
                    seriesvector[i].actorNames.push_back(UpperString(actor));
                    actor.clear();
                }
            }
        }
        seriesvector[i].actorNames.push_back(UpperString(actor));
        actor.clear();
        i++;
    }
    
    
    while (getline(epifile, epiline)) {
        
        istringstream x(epiline);
        bool epiassigned=false;
        bool datedone=false;
        bool codedone=false;
        bool slotdone=false;
        string epiname="";
        string tempmonth, tempday, tempyear, epislot;
        Date epidate;
        episode currentepi;
        int d, m, y;
        
        while (x>>word) {
            if (codedone==false) {
                number=atoi(word);
                codedone=true;
            }
            else if (codedone && !datedone) {
                tempmonth=word.substr(0,word.find("/"));
                word.erase(0,tempmonth.length()+1);
                tempday=word.substr(0,word.find("/"));
                word.erase(0,tempday.length()+1);
                m=atoi(tempmonth);
                d=atoi(tempday);
                y=atoi(word);
                epidate=Date(m, d, y);
                datedone=true;
            }
            else if (datedone && !slotdone) {
                epislot=word;
                slotdone=true;
            }
            else if (slotdone) {
                epiname=epiname+" "+word;
            }
        }
        epiname.erase(0,1);
        currentepi.seriesCode=number;
        currentepi.date=epidate;
        currentepi.slot=UpperString(epislot);
        currentepi.episodeName=UpperString(epiname);
        
        int i=0;
        while (!epiassigned) {
            if (seriesvector[i].seriesCode==number) {
                seriesvector[i].episodes.push_back(currentepi);
                epiassigned=true;
            }
            else {
                i++;
            }
        }
    }

    cout<<"Welcome to my favorite TV series schedule program!"<<endl;
    cout<<"Please, enter your name and surname: ";
    cin>>name>>surname;
    ToUpper(name);
    ToUpper(surname);
    
    getFullName();
    do {
        printmenu();
        cin>>choice;


        if (choice==1) {

        }
        else if (choice==2) {

        }
        else if (choice==3){

        }
        else if (choice==4){

        }
        else if (choice==5){

        }
        else if (choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5 && choice!=6) {
            cout<<"Invalid option!"<<endl;
        }

    } while (choice!=6);

    cout<<"Goodbye, "<<name<<" "<<surname<<" !"<<endl;

    seriesfile.close();
    epifile.close();

    return 0;
}

