#include "Student.h"
#include "utilities.h"
#include <sstream>

std::string Student::to_str()
{
    //log(this, "Student::to_str()");
    std::stringstream ss;
    ss << get_name() << '\t' << gpa << std::endl;
    return ss.str();
}

Student::Student() : Person(), gpa(0.0)
{
    //log(this, "Student()");
}

Student::Student(std::string n, double g) : Person(n), gpa(g)
{
    //log(this, "Student(std::string, double)");
}

Student::Student(const Student &s) : Person(s), gpa(s.gpa)
{
    //log(this, "Student(const Student &)");
}

Student& Student::operator=(const Student &rhs)
{
    //log(this, "Student::operator=(const Student &)");
    Person::operator=(rhs);
    gpa = rhs.gpa;
    return *this;
}

double Student::get_gpa()
{
    //log(this, "Student::get_gpa()");
    return gpa;
}
void Student::set_gpa(double g)
{
    //log(this, "Student::set_gpa(double)");
    gpa = g;
}