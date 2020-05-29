#include "01_Vect.h"
#include <stdexcept>
using namespace std;

std::ostream& operator<<(std::ostream &os, const Vect &rhs)
{
    os << "size: " << rhs.size() << '\t' << "capacity: " << rhs.capacity() << std::endl;
    for (int i = 0; i < rhs.size(); ++i)
        os << rhs.at(i) << ' ';
    os << std::endl;
    return os;
}

Vect::Vect() : sz(0), cap(10), arr(nullptr)
{
    arr = new char[cap];
}

int Vect::size() const
{
    return sz;
}


int Vect::capacity() const
{
    return cap;
}

char& Vect::operator[](int idx)
{
    return at(idx);
}

char& Vect::at(int idx)
{
    if (idx >= sz || idx < 0)
        throw std::runtime_error("Out of bounds.");
    return arr[idx];
}

char const& Vect::at(int idx) const
{
    if (idx >= sz || idx < 0)
        throw std::runtime_error("Out of bounds.");
    return arr[idx];
}

void Vect::push_back(char val)
{
    if (sz == cap)
        resize(cap * 2);
    arr[sz] = val;
    sz += 1;
}

void Vect::resize(int newCap)
{
    int noCopy = (newCap < sz) ? newCap : sz;
    char *tmp = new char[newCap];
    for (int i = 0; i < noCopy; ++i)
        tmp[i] = arr[i];
    sz = noCopy;
    cap = newCap;
    delete [] arr;
    arr = tmp;
}