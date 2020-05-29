#include <iostream>
#include "MyArray.h"
#include "removeValue.h"

using namespace std;

int main()
{
    MyArray array {new int[4], 4, 0};

    for (unsigned int i = 0; i < array.capacity; ++i) {
        array.arr[i] = i % 2; array.size += 1;
    }

    removeValue(array, 1);

    return 0;
}