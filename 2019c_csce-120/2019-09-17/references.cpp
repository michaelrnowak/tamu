#include <iostream> // input and output library, includes cin and cout
// My library code to print objects, references, pointers, and arrays:
#include "../utilities/PrintVisualV2.h"

void AddOne(int &);

using namespace std; // so we do not have to prepend std:: to everything

int main() // function were execution begins
{
    int Eric = 13; // declaraiton of an int variable, initialized with 13

    vis::print_obj(Eric);

    /*
     * Declaration of a reference.  This is the binding of a name to a pre-existing
     * object.  You should think of a reference as a nickname (or another name)
     * for the same object.  In the declartion below, Eazyne and Eric refer to the
     * same object in memory.  Therefore, you can manipulate the object using
     * either name.
     */
    int &Eazye = Eric; // Eazye is a nickname (reference) for Eric

    vis::print_ref(Eazye, "i", "r");

    /*
     * You are making an assignment to the object bound to Eazyne; this is the same
     * object that is bound to Eric. You can verify this by cout-ing the address of the
     * object bound to Eric and/or Eazye. cout << &Eric << '\t' << &Eazye << endl;
     */
    Eazye = 2;

    vis::print_obj(Eric);

    AddOne(Eazye); // see notes beginning on line-44

    vis::print_obj(Eric);


    return 0; // return zero from main() to indicate success
}

/*
 * The parameter of AddOne is a reference.  This means that the argument to the
 * function is bound to this parameter: spider becomes another name for that object.
 * Therefore, when AddOne is invoked on line 35 with Eazye, Spider becomes a name
 * for the object bound to Eazye within the scope of this function.  At that point,
 * main::Eric, main::Eazye, and AddOne::spider are all names for the same object.  It
 * is important to note that Eric and Eazye only have meaning throughout main;
 * spider in AddOne. If we make an assignment to the object through any of these names,
 * we can see the change by accessing the object through any of those names.
 *
 * Note: AddOne must be called with a named object for the argument; you cannot call it
 * with a literal value [AddOne(11) won't work].
*/
void AddOne(int &spider)
{
    cout << "entering function" << endl;
    vis::print_ref(spider, "Eric", "spider");
    spider += 1;
    cout << "exiting function" << endl;
}