#include <iostream>
#include "../utilities/PrintVisualV2.h"

using namespace std;

/*
 * Three ways to declare a function that takes a
 * two-dimensional array *living on the stack* as an argument.  2/3 of the methods below have
 * definitions that are dependent on the size of the array.  The last
 * assumes an array on the stack that is laid out in memory as
 * contiguous block (see jot.pdf), so we pass the address to the first element
 * in this sequence then perform the necessary offsets to visit each element.
 */
void print2Darray(int a[2][3]); // noRows and noCols explicitly provided in param
void print2Darray(int a[][3], const unsigned int); // noCols explicit in first param; noRows pass as second param,
void print2Darray(const int *, const unsigned int, const unsigned int);

int main()
{

    const unsigned int noRows = 2;
    const unsigned int noCols = 3;
    //int arr2[noRows][noCols] {{1, 2, 3}, {4, 5, 6}};
    //int arr2[][noCols] {1, 2, 3, 4, 5, 6}; // initialized array; number of rows inferred
    int arr[noRows][noCols]; // uninitialized array

    // making assignments to an uninitialized 2d array
    /* For our arr[2][3], assignments follows
     *       col0  col1  col2
     * row0|  0     1     2
     * row1|  3     4     5
     */
    for (int i = 0; i < noRows; ++i) {
        for (int j = 0; j < noCols; ++j) {
            arr[i][j] = j + i * noCols;
        }
    }

    cout << "Printing array values using our three functions (in order of declarations)" << endl;
    print2Darray(arr);
    cout << endl;
    print2Darray(arr, noRows);
    cout << endl;
    print2Darray(&arr[0][0], noRows, noCols);

    cout << endl << "Printing the addresses of each element of the array as integer values" << endl;
    vis::print2DarrayAddresses(&arr[0][0], noRows, noCols);
    cout << endl << endl;

    cout << "Figuring out what arr[row][col] syntax is actually doing" << endl;
    cout << "prints addresses of arr, arr[0], etc." << endl;
    cout << "arr : " << vis::asmaskedint(arr) << endl;
    cout << "arr[0] : " << vis::asmaskedint(arr[0]) << endl;
    cout << "arr[1] : " << vis::asmaskedint(arr[1]) << endl;
    cout << "arr[1] + 1 : " << vis::asmaskedint(arr[1] + 1) << endl << endl;

    cout << "priting result of *(arr[1] + 1); this is value in array, but which one" << endl;
    cout << "*(arr[1] + 1) : " << *(arr[1] + 1) << endl;
    // *(arr[row] + col) --> arr[row][col]


    return 0;
}

void print2Darray(int a[2][3])
{
    for (unsigned int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << a[i][j] << '\t';
        }
        cout << endl;
    }
}

void print2Darray(int a[][3], const unsigned int noRows)
{
    for (unsigned int  i = 0; i < noRows; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << a[i][j] << '\t';
        }
        cout << endl;
    }
}

void print2Darray(const int *arr, const unsigned int noRows, const unsigned int noCols)
{
    for (unsigned int  i = 0; i < noRows; ++i) {
        for (unsigned int  j = 0; j < noCols; ++j) {
            //arr[i][j]
            cout <<  *(arr + (i * noCols + j)) << '\t';
        }
        cout << endl;
    }
}