#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cout << str.size() << endl;
    if (str.empty())
        cout << "str is empty" << endl;
    string str2 = "Hello";
    str2 += ", World!";
    cout << str2 << endl;

    for (unsigned int i = 0; i < str2.size(); ++i)
        str += str2.at(i);
    cout << str << endl;


    return 0;
}