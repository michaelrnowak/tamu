#include <cmath>
int amax(const double *, const unsigned int);

int main()
{
    double arr[] {1.0, -3.0};
    int amaxidx = amax(arr, 2);
    return 0;
}

int amax(const double *x, const unsigned int len)
{
    int maxidx = 0;
    for (unsigned int i = 0; i < len; ++i) {
        if (fabs(x[i]) > fabs(x[maxidx]))
            maxidx = i;
    }
    return maxidx;
}