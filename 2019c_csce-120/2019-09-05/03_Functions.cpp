/*

    This file contains our definitions for the
    functions we've written to implement the
    quadratic formula solver.

*/

/* by convention, we #include the header file containing the declarations for the functions defined within this file */
#include "03_Functions.h"

#include <iostream> // input and output library, includes cin and cout

/* sqrt(), pow(a,b) a^b, and fabs() are all used in
this file; therefore, we must #include <cmath> to use them. */
#include <cmath>

using namespace std; // so we do not have to prepend std:: to everything

double solveLinearEquation(double b, double c)
{
    return -c / b;
}

double calcDiscriminate(double a, double b, double c)
{
    return pow(b, 2) - 4 * a * c;
}

bool areNearlyEqual(double x, double y, double epsilon)
{
    /* returns true if x and y are nearly equal,
    if they are within epsilon of one another*/
    return fabs(x - y) <= epsilon;
}

double calculateRealRoot(double a, double b, double c, bool isPositiveRoot)
{
    double p1 = firstPartOfRoot(a, b);
    double p2 = SecondPartOfRoot(calcDiscriminate(a, b, c), a);
    if (isPositiveRoot != false)
        return p1 + p2;
    else
        return p1 - p2;

}
double firstPartOfRoot(double a, double b)
{
    return -b / (2 * a);
}

double SecondPartOfRoot(double disc, double a)
{
    return sqrt(disc) / (2 * a);
}