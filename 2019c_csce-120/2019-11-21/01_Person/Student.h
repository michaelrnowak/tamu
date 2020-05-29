#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include "utilities.h"
#include <string>
#include <iostream>

class Student : public Person {
public:
    Student();
    Student(std::string, double);
    Student(const Student&);
    Student& operator=(const Student &);

    double get_gpa();
    void set_gpa(double);

    std::string to_str();

private:
    double gpa; // shouldn't really store a gpa as a double... why?
};

#endif