#include "Circle.h"
#include <cmath>

Circle::Circle(double r) : radius(r) {}

double Circle::area() {return pow(radius, 2) * M_PI;}
double Circle::perimeter() {return 2 * radius * M_PI;}