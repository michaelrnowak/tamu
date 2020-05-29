/**********************

This program continuously reads white-space delimited, zero-terminated
sequence of numbers from standard input.  Each number read and added
to an accululator with exception of the sentinel value 0.  The sum of
the sequence is then print to standard output.

**********************/

#include <iostream> // input and output library, includes cin and cout

using namespace std; // so we do not have to prepend std:: to everything

int main() // function were execution begins
{

    int sum = 0;

    int val;
    cin >> val;
    while (val != 0) {
        sum += val; // sum = sum + val;
        cin >> val; // why is the last thing we do?
    }
    cout << sum << endl;

    return 0; // return zero from main() to indicate success
}