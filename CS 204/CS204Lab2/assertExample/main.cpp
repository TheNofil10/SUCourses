#include <iostream>
#include <cassert>
#include "buggyDice.h"

using namespace std;

/* Author: Zeynep Dogmus
This program includes an assertion to make sure that the dice value is not 0
*/

const int DICE_SIDES = 6;
int main()
{
    int k, value;
	int numberOfTrials = 10;

    BuggyDice d(DICE_SIDES);

	#ifdef _DEBUG
		cout << "A dice with " << DICE_SIDES << " sides has been created" << endl;
	#endif

    for(k=0; k < numberOfTrials; k++) 
    {   		
		//Roll the dice
		value = d.Roll();
		cout << "Current roll is: " << value << endl;
		assert (value!=0);
    }

	system ("Pause");
	return 0;
}
