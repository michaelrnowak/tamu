#include <iostream> // input and output library, includes cin and cout
// My library code to print objects, references, pointers, and arrays:
#include "../utilities/PrintVisualV2.h"

using namespace std; // so we do not have to prepend std:: to everything

int main() // function were execution begins
{

    double duo = 7.0;  // declaration of an double variable, initialized with 13
    vis::print_obj(duo);
    cout << endl;

    /*
     * Declaration of a reference to duo.  A reference is the binding of a name to a
     * pre-existing object.  Therefore, anotherNameForDuo and duo refer to the same
     * object.  We can interact with the underlying object through either name.
     */
    double &anotherNameForDuo = duo;

    /*
     * Declaration of a pointer to a double.  You can think of a pointer as the
     * "address" type, given that a pointer's value is an address.  Therefore, and
     * unlike with a reference, the declaration of a point creates an object.
     * To get the address of an object to initializer the pointer object we're
     * declaring, we use the address-of operator (&).  Note: & has different meaning
     * when it is used as a declarator operator in a declaration (creates reference) vs.
     * when used in an expression (reveals an object's address).  When reading objects
     * of compound types (pointers and arrays), read the declaration from the right to
     * left: addressForDuo is a pointer to a double.  That pointer is initialized with
     * the address of duo.
     */
    double *addressForDuo = &duo;
    vis::print(addressForDuo, "addressForDuo");
    cout << endl;

    /* Given that a pointer is an object in its own right, we can get its address using
     * the address of operator.  &addressForDuo gives the address of the pointer
     * object.  We can get the value stored in the pointer by writing the name of the
     * variable, just like you'd have done for the variable duo.  In this case, writing
     * addressForDuo gives us the address of duo (because that's what this pointer is
     * currently storing).  If you want to access the object being pointed to, you
     * need to use the dereference operator (*).  Writing *addressForDuo says to go
     * to the address stored in addressForDuo in memory, and begin interpreting that
     * memory according to the base type (here double, because addressForDuo is a
     * pointer to a double).
     */
    cout << &addressForDuo << '\t' << addressForDuo << '\t' << *addressForDuo << endl << endl;
    /* Let's say we want to assign a value to the object being pointed to by
     * addressForDuo.  To do this, we need to dereference addressForDuo to get the
     * object that's being pointed to.  We can perform the dereference operation on the
     * left-hand side of the assignment operator if we'd like to assign a value to the
     * object being pointed to.
     */
    *addressForDuo = 2.0;
    vis::print(addressForDuo, "addressForDuo");
    cout << endl << endl;

    /* Let's break things now.  We can assign different values to pointers too.  We
     * just need to make sure what we assign is an address.  Later today,
     * we will talk about pointer arithmetic.  The expression below subtracts
     * (2 * sizeof(double)) from the base address.  Why is it this and not 2?  Well the
     * by definition, pointer arithmetic is always (int * sizeof(base_type)).
     */
    addressForDuo -= 2; // addressForDuo no longer points to duo!!!
    vis::print(addressForDuo, "addressForDuo");
    cout << endl << addressForDuo << '\t' << *addressForDuo << endl;

    return 0; // return zero from main() to indicate success
}