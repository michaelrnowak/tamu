#include <iostream> // input and output library, includes cin and cout
// My library code to print objects, references, pointers, and arrays:
#include "../utilities/PrintVisualV2.h"

using namespace std; // so we do not have to prepend std:: to everything

void printMe(int *, const int);

int main() // function were execution begins
{

    /* This shows how to declare and initialize an array of integers.  The name
     * of an array evaluates to the base address of that array.
     *       cout << arr1; // prints the address of the first element
     * You can think of the array's name as a pointer that stores the address
     * of the first element!
     */
    int arr1[] {1, 2, 3};
    vis::print(arr1);

    /*
     * How do we access the elements of an array?  If the name of the array evaluates
     * to the base type of the array, we could use pointer arithmetic to offset the
     * address and then dereference the result.
     */
    cout << arr1 << '\t' <<  *arr1 << endl << endl;
    cout << (arr1 + 1) << '\t' <<  *(arr1 + 1) << endl << endl;
    cout << (arr1 + 2) << '\t' <<  *(arr1 + 2) << endl << endl;

    /*
     * There's an easier way though -- we can just use subscripting.  To access the
     * ith element of an array named arr, we would write arr[i] which is equivalent
     * to writing *(arr + i).  Subscripting (arr[i]) combines two operations:
     * (1) performs pointer arithmetic to the base address (arr + 1); (2) dereferences
     * the result of (1).
     */
    cout << endl << arr1[0] << '\t' << *(arr1 + 0) << endl;
    cout << arr1[1] << '\t' <<  *(arr1 + 1) << endl;
    cout << arr1[2] << '\t' << *(arr1 + 2) <<  endl;

    /*
     * Arrays are not self-describing: they do not know their own size.  Therefore,
     * we will construct a variable storing the array's size that will follow the
     * array wherever that array goes.  We can do this by declaring a const int
     * storing the size, then declare an uninitialized array of that size.
     * Thereafter, we can make assignments of reasonable starting values to each
     * element of the array.
     */
    const int arr2_sz = 3;
    int arr2[arr2_sz]; arr2[0] = 1; arr2[1] = 2; arr2[2] = 3;
    vis::print(arr2);

    /*
     *  As previously mentioned, an array does not know its own size.  Therefore,
     * it is necessary to pass a variable denoting an array's size along with it.
     * I've written a printMe function that loops through each element of an array,
     * writing its value to standard output.  The function's first argument is the
     * address of the array that we're interested in printing (the parameter initialized is therefore a pointer to an int).  The second argument is the size
     * of the array (the parameter initialized is therefore an int).
     */
    printMe(arr2, arr2_sz);
    cout << endl;

    /*
     * We cannot compare two arrays by simply writing statements such as (arr1 == arr2).
     * This is because the name of the array evaluates to the address of the first
     * element in the array. Consequently, statements such as (arr1 == arr2) are
     * comparing addresses and not the values of the array.  If you wanted to see
     * whether two arrays contained the same values, you'd need to write a for-statement
     * and check whether each corresponding element between the arrays are the same.
     */
    if (arr1 == arr2) {
        cout << "Same" << endl;
    } else
        cout << "Different" << endl;

    /*
     * You can create an array of characters.  Using the
     *                               char Texas[] = {'T', 'e', 'x', 'a', 's'};
     * syntax, you can interact with the character array in the same manner as
     * an array of ints.  This is not a c-style string and will not work if
     * correctly if you write cout << Texas;.  To print the characters, you
     * have to know the size of the character array and use a for-statement to
     * print its contents.
     *
     * If you would like to create a c-style string, you need to null terminate
     * the the array if using the syntax above.  This looks like
     *                          char Texas[] = {'T', 'e', 'x', 'a', 's', '\0'};
     * This is a c-style string.  The terminating '\0' acts as a sentinel value,
     * demarcating the boundary of the array.  When we use a sentinel value,
     * we don't need to worry about passing the size of the array around. We know
     * we've reached the end of the c-style string when we hit '\0' (int value 0).
     * Writing cout << Texas; will print each of the characters of the array to
     * standard output.  As long as the character array is null terminated, we
     * don't need to use a for-statement to print it to std out.
     */
    //char Texas[] = {'T', 'e', 'x', 'a', 's'}; // *not* terminated with null character
    //cout << Texas << endl;
    char Texas1[] = {'T', 'e', 'x', 'a', 's', '\0'}; // *not* terminated with null character
    cout << Texas1 << endl;

    /* It is common to use strings in our programs.  Therefore, we can create a
     * c-style string by writing char Texas2[] = "Texas";.  This syntax will
     * automatically terminate the string with the null character.  Although we
     * see five characters in the initializer, the string will actually be six
     * characters in length ('T', 'e', 'x', 'a', 's', '\0').
     */
    char Texas2[] = "Texas"; // terminated with null character '\0'
    vis::print(Texas2);
    cout << Texas2 << endl;

    /* We can leverage the sentinel value used to demarcate the boundary of
     * c-style strings.  If we want to iterate through the c-style string,
     * we can say "while the character we're on is not the
     *             null character, do something".
     * I've illustrated this below.
     */
    for (int i = 0; Texas2[i] != 0; ++i) // loop and print characters until hit null character
        cout << Texas2[i] << '\t';
    cout << endl;


    return 0; // return zero from main() to indicate success
}

void printMe(int *arr, const int sz)
{
    for (int i = 0; i < sz; ++i) {
        cout << arr[i] << '\t';
    }
    cout << endl;
}