#include <iostream>
#include "MyArray.h"
#include "03_linearSearch.h"
#include "03_binarySearch.h"

using namespace std;

int main()
{
    MyArray ma1;
    ma1.arr = new int[7];
    ma1.capacity = 7;
    ma1.size = 7;
    for (unsigned int i = 0; i < ma1.size; ++i)
        ma1.arr[i] = i * 10;

    unsigned int idxofvalue = linearSearch(ma1, 20);
    cout << "Linear search result : [" << idxofvalue << "] " << ma1.arr[idxofvalue] << endl;

    unsigned int idxofvalue2 = binarySearch(ma1, 20);
    cout << "Binary search result : [" << idxofvalue2 << "] " << ma1.arr[idxofvalue2] << endl;

    return 0;
}