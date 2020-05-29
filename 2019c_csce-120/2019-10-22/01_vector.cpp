#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vect;
    cout << vect.size() << endl;
    //vect.push_back(7);
    for (unsigned int i = 0; i < 10; ++i) {
        vect.push_back(i * 2);
    }
    for (unsigned int i = 0; i < vect.size(); ++i)
        cout << vect.at(i) << '\t';
    cout << endl;


    return 0;
}