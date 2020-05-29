/*

    This file contains the same solution that we wrote in
    01_QuadraticFormulaSolver.cpp; however, the declarations of the
    functions that we've written were removed from it and placed in
    03_Functions.h.  The definitions for those functions were
    removed from here too and placed in 03_Functions.cpp.

    Therefore, in order to compile this solution, you must
    ensure that you've #include "03_functions.h" in this file and
    provide both 03_QuadraticFormulaSolver.cpp and 03_Functions.cpp to
    the C++ compiler:
        g++ -std=c++14 03_QuadraticFormulaSolver.cpp 03_Functions.cpp

    Note: in this class, you will NEVER #include a .cpp file in a
    source file; you will never provide a .h file to the command used
    to compile (i.e., "g++ -std=c++14 ...").

*/


#include <iostream> // input and output library, includes cin and cout
#include <cmath> // gives you sqrt(), pow(a,b) a^b, fabs(val)

/* #include "03_Functions.h"  03_Functions.h stores
the declarations for the functions we've written.
#include "03_Functions.h" copies and pastes contents
of the specified file (03_Functions.h) into this file
(03_QuadraticForumulaSolver.cpp) during the
compilation process.  That way, the compiler
understands that, for example, the name
areNearlyEqual refers to a function that has three
double-typed parameters and returns a double.  */
#include "03_Functions.h"

using namespace std; // so we do not have to prepend std:: to everything

int main() // function were execution begins
{

    // Read in a, b, c in format "a, b, c"
    cout << "Enter \"a, b, c\" : ";
    double a, b, c; char throwaway;
    cin >> a >> throwaway >> b >> throwaway >> c;
    // cout << a << "\t" << b << "\t" << c;

    if (a == 0.0)  {
        if (b == 0.0) {
            if (c == 0.0) {
                cout << "Infinite Solutions" << endl;
            } else {
                cout << "No solution" << endl;
            }
        } else {
            cout << "Linear equation case" << endl;
            double root = solveLinearEquation(b, c);
            cout << "x = " << root << endl;
        }
    } else {
        cout << "ruh rho... quadratic equation" << endl;
        double disc = calcDiscriminate(a, b, c);
        cout << "disc" << disc << endl;
        if (areNearlyEqual(disc, 0.0, 1e-5)) {
            cout << "One real root." << endl;
            double root = calculateRealRoot(a, b, c, true);
            cout << "x = " << root << endl;
        } else if (disc < 0) {
            cout << "Two complex roots" << endl;
            double pt1 = firstPartOfRoot(a, b);
            double pt2 = SecondPartOfRoot(-1 * disc, a);
            cout << " x = " << pt1 << " +\\- " << pt2 << "i";

        } else {
            cout << "Two real root" << endl;
            double posRoot = calculateRealRoot(a, b, c, true);
            double negRoot = calculateRealRoot(a, b, c, false);
            cout << " x = " << posRoot << ", x = " << negRoot << endl;
        }
    }

    return 0; // return zero from main() to indicate success
}