#include <iostream>
#include "utilities.h"
#include "Person.h"
#include "Student.h"

using namespace std;

int main()
{
    Student eric ("Eric", 4.0);
    Person p("Eric");
    // Student n;
    // n = eric;

    // int i = 7;
    // {
    //     int j = 8;
    //     int i = 3;
    //     cout << j << '\t' << i << endl;
    // }

    // eric.set_gpa(4.0);
    // cout << eric.get_gpa() << endl;
    // eric.set_name("Eric");
    // cout << eric.get_name() << endl;

    return 0;
}