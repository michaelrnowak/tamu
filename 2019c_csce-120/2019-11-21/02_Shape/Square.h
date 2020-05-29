#ifndef SQAURE_H
#define SQAURE_H
#include "Shape.h"

class Square : public Shape {
public:
	Square(double);
	double area();
	double perimeter();

private:
	double width;
	double height;

};

#endif