#include "03_linearSearch.h"

int linearSearch(MyArray const &mya, int valSearchFor)
{
    for (unsigned int i = 0; i < mya.size; ++i) {
        if (mya.arr[i] == valSearchFor)
            return i;
    }
    return -1;
}