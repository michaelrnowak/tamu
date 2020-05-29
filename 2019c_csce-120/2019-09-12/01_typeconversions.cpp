#include <iostream> // input and output library, includes cin and cout
#include <limits>

using namespace std; // so we do not have to prepend std:: to everything

void printIntArg(int);
void printDoubleArg(double);

int main() // function were execution begins
{
    // tell cout to print floating-point values with precision of double
    cout.precision(std::numeric_limits<double>::max_digits10);

    int i = numeric_limits<int>::max(); // initialize i with largest pos int value
    cout << i << endl;
    //double i2d = i; // implicit widening conversion
    double i2d = static_cast<double>(i); // explicit widening conversion
    //cout << sizeof(int) << '\t' << sizeof(double); // print size of int then double
    cout << i << '\t' << i2d << endl;

    long l = numeric_limits<long>::max(); // long is an integer type, larger than int
    double l2d = static_cast<double>(l); // explicit widening conversion
    //cout << sizeof(long) << '\t' << sizeof(double) << endl;
    cout << l << '\t' << l2d << endl; // l2d is correct magnitude, but precision lost in conversion

    double d = numeric_limits<double>::max(); // max positive value of double
    //cout << d << endl;
    int d2i = d; // implicit narrowing conversion
    // narrowing conversion is one that goes from a type with larger range of values to
    // one with smaller range of values
    //cout << sizeof(double) << '\t' << sizeof(int) << endl;
    cout << d << '\t' << d2i << endl;

    double intDiv = 6 / 2; // intger division.  Result is integer, which is used to
    // initialize a variable of type double (so result is implicitly converted to double)

    double intDiv2 = 6 / 5; // integer division.  Result is integer, which is used to
    // initialize a variable of type double (so result is implicitly converted to double)

    double fpDiv = 6.0 / 5.0; // floating-point division. Result is double, which is used
    // to initialize a variable of type double.

    double fpDiv1 = 6.0 / 5; // mixed-mode (different types on either side of operator)
    // here we use the wider type, so 5 is implicitly converted to double, then floating-
    // point division takes place.  Result is type double, which is used to initialize a
    // variable of type double.

    int x = 6, y = 5;
    double fpDiv2 = static_cast<double>(x) / y; // explicitly convert x value to double
    // so that we have mixed-mode arithmetic.  y is then implicitly converted to double
    // and floating-point division occurs.  The result is type double, which is used to
    // initialize a variable of type double.
    cout << fpDiv2 << endl;

    printIntArg(2); // int a = 2; semantics of argument passing identical to
    // initialization.  Here argument 2 is bound to parameter int a.
    printIntArg(2.0); // int a = 2.0;  Here argument 2 is bound to parameter int a (so
    // 2.0 is implicitly converted to int).
    printIntArg('a'); // int a = 'a'; Here argument 'a' is implicitly converted to type int.

    return 0; // return zero from main() to indicate success
}
void printIntArg(int a)
{
    cout << a << endl;
}
void printDoubleArg(double a)
{
    cout << a << endl;
}