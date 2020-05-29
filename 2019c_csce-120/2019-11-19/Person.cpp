#include "Person.h"
#include "utilities.h"

Person::Person() : name("")
{
    log(this, "Person()");
}

Person::Person(std::string name) : name(name)
{
    log(this, "Person(std::string name)");
}

Person::Person(const Person &rhs) : name(rhs.name)
{
    log(this, "Person(const Person &rhs)");
}

Person::~Person()
{
    log(this, "~Person()");
}

Person& Person::operator=(const Person &rhs)
{
    log(this, "Person::operator=(const Person &rhs)");
    name = rhs.name;
    return *this;
}

void Person::set_name(std::string n)
{
    log(this, "Person::set_name(std::string n)");
    name = n;
}

std::string Person::get_name()
{
    log(this, "Person::get_name()");
    return name;
}
