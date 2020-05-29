#include <iostream>

using namespace std;

struct MyArray {
    int *arr = nullptr;
    int capacity = 0; // no elements can store
    int size = 0; // no elements currently held
};

void removeValue(MyArray &, int);

int main()
{
    MyArray array {new int[8], 8, 0};
    cout << array.arr << '\t' << array.capacity << '\t' << array.size << endl;
    for (int i = 0; i < array.capacity; ++i) {
        array.arr[i] = i % 2;
        array.size += 1;
    }

    for (int i = 0; i < array.size; ++i)
        cout << array.arr[i] << '\t';
    cout << endl;

    removeValue(array, 1);

    for (int i = 0; i < array.size; ++i)
        cout << array.arr[i] << '\t';
    cout << endl;

    return 0;
}

void removeValue(MyArray &mya, int val)
{
    int noRemoved = 0;
    for (int i = 0, j = 0; i < mya.size; ++i) {
        if (mya.arr[i] != val) {
            mya.arr[j] = mya.arr[i];
            j += 1;
        } else {
            noRemoved += 1;
        }
    }
    mya.size -= noRemoved;
}