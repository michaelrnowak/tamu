#include <iostream>
#include "Vect.h"

using namespace std;

int main()
{
    Vect<int> v;
    for (int i = 1; i <= 4; ++i)
        v.push_back(i);
    cout << "v" << endl;
    cout << v << endl;
    Vect<int> v2 = v;
    cout << "v2" << endl;
    cout << v2 << endl;
    v2.at(0) = 100;

    cout << "v" << endl;
    cout << v << endl;
    cout << "v2" << endl;
    cout << v2 << endl;

    Vect<int> v3;
    v3 = v2;
    v2 = v2;

    // cout << "v2" << endl;
    // cout << v2 << endl;
    // cout << "v3" << endl;
    // cout << v3 << endl;
    // v2.at(0) = 500;

    // cout << "v2" << endl;
    // cout << v2 << endl;
    // cout << "v3" << endl;
    // cout << v3 << endl;



    return 0;
}