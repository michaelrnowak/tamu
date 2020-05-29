/**********************

This program reads an integer value from standard input, invokes
noDigits to calculate the number of digits (place values) of that
number, and prints the return value (number of digits) to standard
output.

Accordingly,we also illustrate the forward declaration of a
function and how a function definition is composed.

**********************/

#include <iostream>

using namespace std;

/* Forward declaration of a function follows.  This tells the compiler
that the name noDigits refers to a function that has (in this case) a
single int parameter and returns an int value.  The former indicates
how the function can be called, while the latter dictates the
operations that can be performed on the value returned by the
function. e.g., (noDigits % 4) is a valid expression because modulus
can be applied to integers; had the function returned a double, the
expression would be invalid (modulus not defined for floating-point
numbers) */
int noDigits(int);

int main()
{
    cout << "Enter an integer value : ";
    int val;
    cin >> val;

    int len = noDigits(val);
    cout << len << endl;

    return 0;
}

/* Definition of the function noDigits follows.  The function header,
int noDigits(int no), is almost identical to the function declaration
(exception is that we name the parameter here).  The function body
appears between the {} and dictates the sequence of statements that
will be executed when the function is invoked. */
int noDigits(int no)
{
    if (no == 0) // why did I add this 'check'?
        return 1;

    int len = 0;
    while (no != 0) {
        len += 1;
        no /= 10; // no = no / 10
    }
    return len;
}