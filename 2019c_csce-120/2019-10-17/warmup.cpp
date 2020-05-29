#include <iostream>
using namespace std;

int warmup(int, int);

int main()
{
    cout << warmup(5, 5);
    return 0;
}

int warmup(int m, int n)
{
    if (n == 0)
        return 0;
    return m + warmup(m, n - 1);
}