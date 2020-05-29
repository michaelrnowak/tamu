#include "Square.h"

Square::Square(double side) : width(side), height(side) {}

double Square::area() {return width * height;}
double Square::perimeter() {return 2 * width + 2 * height;}