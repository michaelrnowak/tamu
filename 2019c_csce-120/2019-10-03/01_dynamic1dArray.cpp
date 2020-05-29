#include <iostream>
#include <limits>
#include "/Users/michael/src/cxx-printvisual/PrintVisualV2.h"

using namespace std;

void resizeIntArray(int *&, unsigned int &);

int main()
{
    unsigned int sz = 0; // for tracking the no. of elements in array
    unsigned int capacity = 2; // for tracking the no. of "slots" in the array
    int *arr = new int[capacity]; // array has two slots; both of them are available for data

    /*
     * Let's get some values from standard input to populate our array; we will resize
     * as necessary to store an arbitrary number of input values.
     *
     * At home, try entering input sequences different in length to see how the
     * capacity and size of arr scales with input.
     */

    int val = 0;
    cout << "Enter a zero-terminated sequence of integer values (eg., 1 2 3 0) : ";
    cin >> val;
    while (val != 0) {
        if (cin.bad())
            return 1;
        else if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            if (sz == capacity) { // if there are no available slots for data
                resizeIntArray(arr, capacity); // 'resize' the array
            }
            arr[sz] = val;
            sz += 1;
        }
        cin >> val;
    }
    cout << endl << endl;

    /*
     * Writing out some information about our dynamically allocated array of ints
     */
    cout << "about \"arr\":" << endl;
    cout << "\tcapacity : " << capacity << endl;
    cout << "\tsize: " << sz << endl;
    cout << "\tcontents : " << endl;
    for (unsigned int i = 0; i < sz; ++i)
        cout << "\t\tarr[" << i << "] " << ' ' << arr[i] << endl;
    cout << endl;


    return 0;
}

void resizeIntArray(int *&arr, unsigned int &capacity)
{
    // arr is another name for the pointer in (this example) main()
    // array_sz is another name for capacity in (this example) main()

    /*
     * Step 1.) Allocate memory for the new array of appropriate type and size
     * (here, we elect to make the new size twice the previous).
     */
    int *temp = new int[capacity * 2];

    /*
     * Step 2.) Copy the data from the old array into the new array
     * (keeping the elements at the same position).
     */
    for (int i = 0; i < capacity; ++i)
        temp[i] = arr[i];

    /*
     * Step 3.) Deallocate memory reserved for the old array.
     */
    delete [] arr;

    /*
     * Step 4.) Update the pointer bound to the first parameter to reflect
     * the new address.
     */
    arr = temp;

    /*
     * Step 5.) Update the variable containing the array’s size.
     */
    capacity *= 2;
}
