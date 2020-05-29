#include <iostream>
#include <vector>
#include "Square.h"
#include "Circle.h"

using namespace std;

int main()
{
    Circle c(2);
    Square s(2);
    //Shape s1; //abstract base class, can't be built
    vector<Shape*> shapes;

    shapes.push_back(&c);
    shapes.push_back(&s);

    for (Shape* shape : shapes) {
        cout << shape->area() << endl;
        cout << shape->perimeter() << endl;
        cout << endl;
    }

    return 0;
}