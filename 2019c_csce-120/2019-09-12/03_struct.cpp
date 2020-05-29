#include <iostream>
#include "03_Coordinate.h"

// compiles with "g++ -std=c++14 03_struct.cpp 03_Coordinate.cpp"

using namespace std;

int main()
{
    Coordinate c{10, 20, 15}; // uniform initialization
    // {10, 20, 15} used to initialize data members in the order in which they
    // are declared in the struct definition (i.e., x, y, z)

    // a variable declaration; gives it a  (i) base type;
    //                                 (ii) name
    //                                (iii) starting value
    // (i)-a tells the compiler how much space is needed
    //      Coordinate will need 3 x sizeof(int) space
    // (i)-b operations we can perform on the variable.
    //      We've defined no operations (behaviors) for Coordinate

    cout << '(' << c.x << ',' << c.y << ',' << c.z << ')' << endl; // prints (10,20,15)

    c.x = 30; // assign c's x a different value
    c.y = 45; // assign c's y a different value
    c.z = 90; // assign c's z a different value

    cout << c << endl; // uses special function to print c similar to how you'd
    // print any variable previously (eg. "int i = 7; cout << i << endl;")

    return 0;
}