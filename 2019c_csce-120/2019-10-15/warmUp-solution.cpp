#include <iostream>

using namespace std;

struct MyArray {
    int *arr = nullptr;
    unsigned int capacity = 0; // no elements can store
    unsigned int size = 0; // no elements currently held
};

void openAtIdx(MyArray &mya, unsigned int, int);

int main()
{
    MyArray array{new int[18]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 18, 9};
    cout << "array (size:" << array.size << ";capacity:" << array.capacity << ")" << endl;
    for (unsigned int i = 0; i < array.size; ++i)
        cout << array.arr[i] << endl;
    cout << endl;

    openAtIdx(array, 3, 100);

    cout << "array (size:" << array.size << ";capacity:" << array.capacity << ")" << endl;
    for (unsigned int i = 0; i < array.size; ++i)
        cout << array.arr[i] << endl;
}

void openAtIdx(MyArray &mya, unsigned int idx, int valueToAdd)
/* desired behavior: shift all elements "up" from idx, "opening up" position
 * idx for assignment of valueToAdd.  This operation increases the "size" of the
 * MyArray object by 1; therefore, the operation would require a resize if
 * (size == capacity)! Here, we've written the function to simply terminate the
 * program should (size == capacity).  If the input to this function is
 * mya={arr->[1,2,3, 4],capacity=10,size=4}, idx=2, and valueToAdd=100; the
 * side-effect on is mya={arr->[1,2,100,3,4],capacity=10,size=5}.
 */
{
    if (mya.size == mya.capacity)
        exit(1);

    mya.size += 1;
    int last = mya.arr[idx];
    for (unsigned int i = idx + 1; i < mya.size; ++i) {
        int curr = mya.arr[i];
        mya.arr[i] = last;
        last = curr;
    }
    mya.arr[idx] = valueToAdd;
}
