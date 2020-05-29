#include <iostream>
#include <limits>

using namespace std;

int main()
{
    if (0.1 + 0.2 == 0.3)
        cout << "Adds up as expected!" << endl;
    else
        cout << "Floating point math *must* be broken?" << endl;

    // tell cout to print floating-point values with precision of double
    cout.precision(std::numeric_limits<double>::max_digits10);

    cout << "0.1 + 0.2 == 0.3" << endl;
    cout << (0.1 + 0.2) << " == " << 0.3 << endl;

    return 0;
}