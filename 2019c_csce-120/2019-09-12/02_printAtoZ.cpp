#include <iostream>

using namespace std;

int main()
{

    for (char c = 'A'; c <= 'Z'; ++c)
        cout << c << ' ';
    cout << endl;

    for (int c = 'A'; c <= 'Z'; ++c)
        cout << c << ' ';
    cout << endl;

    for (int c = 'A'; c <= 'Z'; ++c)
        cout << static_cast<char>(c) << ' ';
    cout << endl;

    return 0;
}