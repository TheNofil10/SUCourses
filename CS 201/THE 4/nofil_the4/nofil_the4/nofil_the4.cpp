#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "strutils.h"

using namespace std;

int main()
{
    ifstream inpool, intext;
    string pooltext, maintext, textword, poolword, textline, poolline, lowertextword, lowerpoolword, output;
    int textlen, poollen, i, same, replacements, maxmatches;
    bool case1=false, case2=false, case3=false, case4=false;
    
    cout<<"Please enter a filename for the word pool: ";
    cin>>pooltext;
    inpool.open(pooltext.c_str());
    
    while(inpool.fail())
    {
        cout<<"Cannot open the word pool file."<<endl;
        cout<<"Please enter a filename for the word pool: ";
        cin>>pooltext;
        inpool.open(pooltext.c_str());
    }
    
    cout<<"Please enter a filename for the main text: ";
    cin>>maintext;
    intext.open(maintext.c_str());
    
    while(intext.fail())
    {
        cout<<"Cannot open the main text file."<<endl;
        cout<<"Please enter a filename for the main text: ";
        cin>>maintext;
        intext.open(maintext.c_str());
    }
    cout<<"You may find the results below:"<<endl;
    
    while(getline(intext, textline)) //takes line from main text file
    {
        istringstream in(textline);
        while(in>>textword) //takes main text word from main text line
        {
            maxmatches=0;
            string output="";
            replacements=0;
            textlen=textword.length();
            inpool.clear();
            inpool.seekg(0);
            case1=case2=case3=case4=false;
            while(inpool>>poolword)//takes word from word pool file
            {
                poollen=poolword.length();
                if(textlen==poollen)
                {
                    same=0;
                    i=0;
                    lowertextword=LowerString(textword);
                    lowerpoolword=LowerString(poolword);
                    while(i<textlen)
                    {
                        if(lowertextword.at(i)==lowerpoolword.at(i))
                        {
                            same++;
                            if(same>maxmatches)
                            {
                                maxmatches=same;
                            }
                        }
                        i++;
                    }
                    if(same>=textlen/2 && same==maxmatches)
                    {
                        replacements++;
                        if(replacements==1)
                        {
                            output+=poolword;
                        }
                        else
                        {
                            output=output+","+poolword;
                        }
                    }
                    if(same==textlen)
                    {
                        case1=true;
                    }
                }
            }
            if(replacements==1)
            {
                case2=true;
            }
            else if(replacements>1)
            {
                case3=true;
            }
            else if(replacements==0)
            {
                case4=true;
            }
            
            if(case1==true)
            {
                cout<<textword;
            }
            else if(case2==true)
            {
                cout<<output;
            }
            else if(case3==true)
            {
                cout<<"("<<output<<")";
            }
            else if(case4==true)
            {
                cout<<"{"<<textword<<"}";
            }
            cout<<" ";
        }
        cout<<endl;
    }
    
    inpool.close();
    intext.close();
    return 0;
}
