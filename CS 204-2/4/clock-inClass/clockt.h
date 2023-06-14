#ifndef _CLOCKTIME_H
#define _CLOCKTIME_H

#include <iostream>
#include <string>
using namespace std;


class ClockTime{
  public:
    
    ClockTime();
    ClockTime(int secs, int mins, int hours);

    int     Hours()        const;        // returns # hours
    int     Minutes()      const;        // returns # minutes
    int     Seconds()      const;        // returns # seconds
    string  tostring()     const;        // converts to string
    
    bool    Equals(const ClockTime& ct) const; // true if == ct
    bool    Less  (const ClockTime& ct) const; // true if < ct
    
  private:
  
    void Normalize();        // < 60 secs, < 60 min
  
    int mySeconds;           // constrained: 0-59    
    int myMinutes;           // constrained: 0-59
    int myHours;

};

#endif
