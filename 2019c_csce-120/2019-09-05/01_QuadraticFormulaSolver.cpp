/*

    This file contains our solution to the quadratic formula solver
    program.  In this version, the forward declarations and function
    definitions are stored within this file.  We later move the
    declarations and definitions into their own header and source
    files respectively.  This is done in the files prefixed with 03_.

    If you got lost during class, please play computer and trace
    through this code.  This is a great exercise that will help
    you develop your ability to read code, which will be important
    come exam time.

*/

#include <iostream> // input and output library, includes cin and cout
#include <cmath> // gives you sqrt(), pow(a,b) a^b, fabs(val)

using namespace std; // so we do not have to prepend std:: to everything

double solveLinearEquation(double, double);
double calcDiscriminate(double, double, double);
bool areNearlyEqual(double, double, double);
double calculateRealRoot(double, double, double, bool);
double firstPartOfRoot(double, double);
double SecondPartOfRoot(double, double);


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