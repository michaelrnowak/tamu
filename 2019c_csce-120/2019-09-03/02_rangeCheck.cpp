/**********************

This program continuously requests that user enter an integer to
standard input, until that integer is within [minVal, maxVal].

**********************/


#include <iostream> // input and output library, includes cin and cout

using namespace std; // so we do not have to prepend std:: to everything

const int minVal = 5000;
const int maxVal = 10000;

int main() // function were execution begins
{

    cout << "Hey... enter a value between " << minVal << " and " << maxVal << " please...";

    int valRead;
    cin >> valRead;

    while (valRead < minVal || valRead > maxVal) {
        cout << "Hey! That number is not in the correct range -- try again!  Enter an integer value between " << minVal << " and " << maxVal << " please...";
        cin >> valRead;
    }

    cout << "I read : " << valRead << endl;

    return 0; // return zero from main() to indicate success
}