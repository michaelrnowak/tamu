#include <iostream>
#include "02_Vect.h"

using namespace std;

int main()
{
    Vect<char> v;
    for (int i = 97; i < 107; ++i)
        v.push_back(i);
    cout << v.size() << '\t' << v.capacity() << endl;
    v.push_back(107);
    cout << v.size() << '\t' << v.capacity() << endl;
    //v.at(0) = 10;

    cout << v << endl;
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    cout << endl;

    Vect<int> v2;
    for (int i = 97; i < 107; ++i)
        v2.push_back(i);
    cout << v2 << endl;

    Vect<int> v3;

    return 0;
}