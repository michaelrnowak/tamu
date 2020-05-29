#include "03_Coordinate.h"
using namespace std;

// Definition to allow Coordinate object to be used with cout
// dont need to worry about this special function right now.
// This prints "(x,y,z)" when "cout << c", where c is a Coordinate object.
std::ostream& operator<<(std::ostream &os, const Coordinate &obj)
{
    os << '(' << obj.x << ',' << obj.y << ',' <<  obj.z << ')' << endl;
    return os;
}
