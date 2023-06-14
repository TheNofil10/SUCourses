#include <iostream>
#include <vector>
#include "dice.h"
#include "date.h"
using namespace std;

/* Program tests if all dice values are equally likely */
/* It is also used to demonstrate 
   a) use of libraries, 
   b) use of built-in arrays
   c) preprocessor directives
   d) user defined types/classes
   e) need for include files

Make sure to learn the above topics, debugging (within the VC++ 
environment, watch windows,...), Release/Debug configurations
*/

#define ARRAY

const int DICE_SIDES = 6;
int main()
{
    int k, value;
	int numberOfTrials = 100;

    Dice d(DICE_SIDES);

#ifdef ARRAY
	//allocates values for indiced 0 to DICE_SIDES, for convenience
    int counter[DICE_SIDES+1]; 
#else
    vector<int> counter(DICE_SIDES+1);
#endif


	for(k=0; k <= DICE_SIDES; k++) 
		counter[k]=0;

    for(k=0; k < numberOfTrials; k++)
    {   
		//Roll the dice
		value = d.Roll();
		//Update number of occurence of value
        counter[value]++;
    }

	for(k=1; k <= DICE_SIDES; k++) 
		cout << "Occurence of dice value " << k << " is " << counter[k] << " " << endl;
	
	system ("Pause");
	return 1;
}
