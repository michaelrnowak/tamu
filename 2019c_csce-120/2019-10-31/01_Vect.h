#ifndef VECT_H
#define VECT_H
#include <iostream>
#include <stdexcept>

class Vect {
public:

    Vect();
    void push_back(char);
    char& at(int);
    char const& at(int idx) const;
    int size() const;
    int capacity() const;
    char& operator[](int);

private:
    int sz;
    int cap;
    char *arr;

    void resize(int);
};

std::ostream& operator<<(std::ostream &, const Vect &);

#endif