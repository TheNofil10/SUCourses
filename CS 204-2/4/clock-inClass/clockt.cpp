#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

#include "clockt.h"
#include "time.h"

/*********************************************************************/
ClockTime::ClockTime(){
    static struct tm timeHolder;
    static struct tm *date = &timeHolder;
    time_t tloc;
    
    time(&tloc);

    date = localtime(&tloc);
    
    mySeconds= date->tm_sec;
    myMinutes= date->tm_min;
    myHours=   date->tm_hour;
}


/*********************************************************************/
ClockTime::ClockTime(int secs, int mins, int hours)
: mySeconds(secs), myMinutes(mins), myHours(hours){
// postcondition: all data fields initialized
    Normalize();
}

/*********************************************************************/
int ClockTime::Hours() const{
// postcondition: return # of hours
    return myHours;
}

int ClockTime::Minutes() const{
// postcondition: return # of minutes
    return myMinutes;
}

int ClockTime::Seconds() const{
// postcondition: return # of seconds
    return mySeconds;
}

/*********************************************************************/
string ClockTime::tostring() const{
    ostringstream os;
    os.fill('0');
    os << this->myHours << ":" << setw(2) << this->myMinutes << ":"
       << setw(2) << this->mySeconds;
    
    return os.str();
}

/*********************************************************************/
void ClockTime::Normalize(){
    myMinutes += mySeconds/60;    // overflow from secs to myMinutes
    mySeconds %= 60;              // now between 0 and 59
    
    myHours += myMinutes/60;      // overflow from myMinutes to myHours
    myMinutes %= 60;              // now between 0 and 59
}

/*********************************************************************/
bool ClockTime::Equals(const ClockTime& c) const{
// postcondition: returns true iff == c
    return myHours == c.myHours &&
           myMinutes == c.myMinutes &&
           mySeconds == c.mySeconds;
}

bool ClockTime::Less(const ClockTime& c) const{
// postcondition: returns true iff < c
    return ( myHours < c.myHours ) ||
           ( ( myHours == c.myHours ) &&
               ( ( myMinutes < c.myMinutes ) ||
                 ( ( myMinutes == c.myMinutes ) && ( mySeconds < c.mySeconds ) )
               )
           );
}




