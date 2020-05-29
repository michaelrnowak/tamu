/* Header */
#ifndef COORDINATE_H
#define COORDINATE_H
#include <iostream>

/* Body */

// Definition of type Coordinate; has three int data members (x, y, z)
struct Coordinate {
    int x;
    int y;
    int z;
}; // don't forget the semi-colon to delineate where type definition ends

// Declaration to allow Coordinate object to be used with cout
// dont need to worry about this right now.
std::ostream& operator<<(std::ostream &, const Coordinate &);

/* Footer */
#endif