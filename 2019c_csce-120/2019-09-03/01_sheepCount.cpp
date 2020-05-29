/**********************

This program counts up from 1-sheep to noSheep and then down from
noSheep to 1-sheep.  It illustrates basic usage of for-statements.

**********************/

#include <iostream> // input and output library, includes cin and cout

using namespace std; // so we do not have to prepend std:: to everything

// Following is the C++ way to define an integer constant
const int noSheep = 9; // number of sheep we'll count

int main() // function were execution begins
{
    for (int sheepCounter = 1; sheepCounter <= noSheep; ++sheepCounter) {
        cout << sheepCounter << " sheep." << endl;
    }

    cout << endl << endl;

    for (int sheepCounter = noSheep; sheepCounter >= 1 ; --sheepCounter)
        cout << sheepCounter << " sheep." << endl;

    return 0; // return zero from main() to indicate success
}