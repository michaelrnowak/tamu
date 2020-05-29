/**********************

This program continuously reads white-space delimited, zero-terminated
sequence of numbers from standard input, and in the process determines
the number of even and odd values within that sequence.

**********************/

#include <iostream> // input and output library, includes cin and cout

using namespace std; // so we do not have to prepend std:: to everything

int main() // function were execution begins
{

    int countEven = 0, countOdd = 0;

    int val;
    cin >> val;
    while (val != 0) {
        if (val % 2 == 0)
            countEven += 1;
        else
            countOdd += 1;
        cin >> val;
    }
    cout << "countEven " << countEven <<  endl;
    cout << "countOdd " << countOdd <<  endl;

    return 0; // return zero from main() to indicate success
}