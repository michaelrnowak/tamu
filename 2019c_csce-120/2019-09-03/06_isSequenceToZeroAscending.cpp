/**********************

This program illustrate one way to determine whether a white-space
delimited, zero-terminated sequence of numbers read from standard
input is increasing (not strictly).

**********************/

#include <iostream>
#include <limits>

using namespace std;

int main()
{

    int curr = numeric_limits<int>::min(); // most negative int that can be stored; maximum would be numeric_limits<int>::max()
    int prev = curr;
    bool isAsc = true;
    while (curr != 0) {
        if (prev > curr) {
            isAsc = false;
            break; // break out of loop; no need to continue looking at numbers as we already know the sequence is not in ascending order
        }
        prev = curr;
        cin >> curr;
    }
    if (isAsc != false)
        cout << "Is ascending" << endl;
    else
        cout << "Is not ascending" << endl;
    return 0;
}