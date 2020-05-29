#include <iostream>

using namespace std;

const unsigned int NOROWS = 2;
const unsigned int NOCOLS = 3;

int main()
{
    /*
     * A two-dimensional dynamic array of integers is constructed as an array of arrays.  Therefore
     * we create a one-dimensional dynamic array whose ELEMENTS are *int.  Given that the elements
     * are pointers, we will store the address to our array of pointers in variable typed int**.
     */

    /*
     * Create an array of NOROWS pointers; each will point to a dynamic array of integers.  arr will
     * be able to store NOROWS pointers.
     */
    int *(*arr) = new int*[NOROWS];

    /*
     * To each element in arr, assign the address of an array of int[NOCOLS]
     */
    for (int i = 0; i < NOROWS; ++i)
        arr[i] = new int[NOCOLS];

    // (!) The result is an NOROWS row by NOCOLS cols dynamically
    // allocated array of integers.

    /*
     * Let's make some assignments to the dynamic two-dimensional array!
     */
    for (unsigned int row = 0; row < NOROWS; ++row) {
        for (unsigned int col = 0; col < NOCOLS; ++col) {
            arr[row][col] = row * NOCOLS + col;
        }
    }

    /*
     * Let's print the values housed in our dynamic two-dimensional array!
     */
    for (unsigned int row = 0; row < NOROWS; ++row) {
        for (unsigned int col = 0; col < NOCOLS; ++col) {
            cout << arr[row][col] << '\t';
        }
        cout << endl;
    }

    /*
     * Deallocating memory for our two-dimensional dynamic array arr.
     * Since we've got an array of arrays, we need to call delete[] on each
     * array created in the for-statement above and then again call delete[] on
     * arr.
     *
     * In fact, in our programs, every call to new must be paired with a call to delete
     * to prevent memory from being leaked.
     */
    for (int i = 0; i < NOROWS; ++i)
        delete [] arr[i];
    delete [] arr;

    return 0;
}