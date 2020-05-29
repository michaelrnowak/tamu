/**********************

This program continuously reads white-space delimited, zero-terminated
sequence of numbers from standard input.  Each number read is print to
standard output, except for the sentinel value 0.

**********************/


#include <iostream> // input and output library, includes cin and cout

using namespace std; // so we do not have to prepend std:: to everything

int main() // function were execution begins
{
    int val;
    cin >> val;

    while (val != 0) {
        cout << val << endl;
        cin >> val;
    }

    return 0; // return zero from main() to indicate success
}