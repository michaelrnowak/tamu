#include <iostream>
#include <vector>
#include "Color.h"

using namespace std;

int main()
{
    vector<int> vect(100, 2);

    Color c1(1, 2, 3);
    // c1.set_r(80);
    // c1.set_g(0);
    // c1.set_b(0);
    cout << to_str(c1) << endl;

    Color *ptr_c2 = new Color(80, 0, 0);
    cout << to_str(*ptr_c2) << endl;
    delete ptr_c2;

    cout << "haven't left main yet" << endl;

    return 0;
}