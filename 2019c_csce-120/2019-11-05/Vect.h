#ifndef VECT_H
#define VECT_H
#include <iostream>
#include <stdexcept>

//////////////////////////////////////////////////////////////////////////////
//                     Vect class template definition                       //
//////////////////////////////////////////////////////////////////////////////

template <typename T>
class Vect {
public:
    Vect();
    Vect(const Vect<T>&); // copy constructor
    void push_back(T);
    Vect<T>& operator=(const Vect<T>&); // copy assignment operator

    T& at(int);
    T const& at(int idx) const;
    int size() const;
    int capacity() const;
    T& operator[](int);

private:
    int sz;
    int cap;
    T *arr;
    void resize(int);
};

//////////////////////////////////////////////////////////////////////////////
//                       Helper Function Declarations                       //
//////////////////////////////////////////////////////////////////////////////

template <typename T>
std::ostream& operator<<(std::ostream &, const Vect<T> &);

//////////////////////////////////////////////////////////////////////////////
//                      Template Function Definitions                       //
//////////////////////////////////////////////////////////////////////////////

template <typename T>
std::ostream& operator<<(std::ostream &os, const Vect<T> &rhs)
{
    os << "size: " << rhs.size() << '\t' << "capacity: " << rhs.capacity() << std::endl;
    for (int i = 0; i < rhs.size(); ++i) {
        os << rhs.at(i) << ' ';
        //os << '\t' << rhs.at(i) << " [" << &rhs.at(i) << "]" << std::endl;
    }
    //os << std::endl;
    return os;
}

template <typename T>
Vect<T>::Vect(const Vect<T>& rhs) : sz(rhs.sz), cap(rhs.cap)
{
    arr = new T[cap];
    for (int i = 0; i < sz; ++i)
        arr[i] = rhs.arr[i];
}

template <typename T>
Vect<T>& Vect<T>::operator=(const Vect<T>& rhs)
{
    if (this == &rhs)
        return *this;
    delete [] arr;
    sz = rhs.sz;
    cap = rhs.cap;
    arr = new T[cap];
    for (int i = 0; i < sz; ++i)
        arr[i] = rhs.arr[i];
    return *this;
}

template <typename T>
Vect<T>::Vect() : sz(0), cap(10), arr(nullptr)
{
    arr = new T[cap];
}

template <typename T>
int Vect<T>::size() const
{
    return sz;
}

template <typename T>
int Vect<T>::capacity() const
{
    return cap;
}

template <typename T>
T& Vect<T>::operator[](int idx)
{
    return at(idx);
}

template <typename T>
T& Vect<T>::at(int idx)
{
    if (idx >= sz || idx < 0)
        throw std::runtime_error("Out of bounds.");
    return arr[idx];
}

template <typename T>
T const& Vect<T>::at(int idx) const
{
    if (idx >= sz || idx < 0)
        throw std::runtime_error("Out of bounds.");
    return arr[idx];
}

template <typename T>
void Vect<T>::push_back(T val)
{
    if (sz == cap)
        resize(cap * 2);
    arr[sz] = val;
    sz += 1;
}

template <typename T>
void Vect<T>::resize(int newCap)
{
    int noCopy = (newCap < sz) ? newCap : sz;
    T *tmp = new T[newCap];
    for (int i = 0; i < noCopy; ++i)
        tmp[i] = arr[i];
    sz = noCopy;
    cap = newCap;
    delete [] arr;
    arr = tmp;
}


#endif