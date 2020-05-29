#include "03_binarySearch.h"
#include <iostream>

int binarySearch(MyArray const &mya, int valSearchFor)
{
    /* return (any) position if valSearchFor is in sorted mya.arr[0..size-1] or -1 if valSearchFor is not present */
    unsigned int lowerBound = 0;
    unsigned int upperBound = mya.size - 1;
    while (lowerBound <= upperBound) {
        unsigned int midpt = (lowerBound + upperBound) / 2;
        if (mya.arr[midpt] < valSearchFor)
            lowerBound = midpt + 1;
        else if (mya.arr[midpt] == valSearchFor)
            return midpt;
        else /* mya.arr[midpt] > valSearchFor */
            upperBound = midpt - 1;
    }
    return -1;
}