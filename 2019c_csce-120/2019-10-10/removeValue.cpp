#include "removeValue.h"
void removeValue(MyArray &mya, int val)
{
    unsigned int noRemoved = 0;
    for (unsigned int i = 0, j = 0; i < mya.size; ++i) {
        if (mya.arr[i] != val) {
            mya.arr[j] = mya.arr[i]; j += 1;
        } else {
            noRemoved += 1;
        }
    }
    mya.size -= noRemoved;
}