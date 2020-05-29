#include <iostream>
#include <vector>
#include "utilities.h"
#include "Person.h"
#include "Student.h"

using namespace std;

int main()
{
    Student eric ("Eric", 4.0);
    Person bill ("Bill");
    cout << eric.to_str() << endl;
    cout << bill.to_str() << endl;

    vector<Person*> people;
    people.push_back(&eric);
    people.push_back(&bill);
    for (Person* person : people) {
        cout << person->to_str() << endl;
    }

    return 0;
}