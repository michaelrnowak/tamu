#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {
public:
    Person();
    Person(std::string);
    Person(const Person&);
    ~Person();
    Person& operator=(const Person&);

    void set_name(std::string);
    std::string get_name();

    virtual std::string to_str();

protected:

private:
    std::string name;
};

#endif