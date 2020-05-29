#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape {
public:
	Circle(double);
	double area();
	double perimeter();

private:
	double radius;
};

#endif
