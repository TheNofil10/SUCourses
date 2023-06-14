#include "buggyDice.h"
#include "randgen.h"

// implementation of dice class
// written Jan 31, 1994, modified 5/10/94 to use RandGen class
// modified 3/31/99 to move RandGen class here from .h file
// modified 18/02/2013 (by Zeynep Dogmus) to add a bug: Roll can return 0

BuggyDice::BuggyDice(int sides)
// postcondition: all private fields initialized     
{
    myRollCount = 0;
    mySides = sides;
}

int BuggyDice::Roll()
// postcondition: number of rolls updated
//                random 'die' roll returned     
{
    RandGen gen;    // random number generator
    
    myRollCount= myRollCount + 1;         // update # of times die rolled
    return gen.RandInt(0,mySides);        // in range [0..mySides]
}

int BuggyDice::NumSides() const
// postcondition: return # of sides of die     
{
    return mySides;
}

int BuggyDice::NumRolls() const
// postcondition: return # of times die has been rolled     
{
    return myRollCount;
}

