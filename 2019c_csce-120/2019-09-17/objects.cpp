#include <iostream> // input and output library, includes cin and cout
// My library code to print objects, references, pointers, and arrays:
#include "../utilities/PrintVisualV2.h"

void interact_obj (int);

using namespace std; // so we do not have to prepend std:: to everything

int main() // function were execution begins
{
    cout << "entering main" << endl << endl;

    int i = 0; // declaraiton of an int variable, initialized with 0
    cout << "int i = 0" << endl;
    vis::print_obj(i, "i");
    cout << endl;

    interact_obj(i);
    cout << endl;
    vis::print_obj(i, "i");
    cout << endl << endl;


    int j = i;
    cout << "int j = 1" << endl;
    vis::print_obj(j, "j");
    cout << endl;

    // j = 7;
    // cout << "j = 7" << endl;
    // vis::print_obj(j, "j");
    // cout << endl;


    cout << endl << "exiting main" << endl;
    return 0; // return zero from main() to indicate success
}

/*
 * When a function is invoked, a stack frame for that function is pushed to the stack.
 * A stack frame (also called an activation record) stores the parameters of and local
 * variables to that function, and other house keeping information.
 *
 * When we invoke interact_obj on line 18, the value stored in main::i is *copied*
 * into the object interact_obj::arg.  At this point, main::i and interact_obj::arg
 * store the same values, but are distinct objects. During the execution of
 * interact_object, the value stored in interact_obj::arg is assigned a new value.
 * main::i and interact_obj::arg no longer store the same value. At the end of this
 * function, memory for arg is deallocated as the stack frame for interact_obj is
 * removed from the stack.
 */
void interact_obj(int arg)
{
    cout << "=============================================" << endl;
    cout << "entering interact_obj" << endl << endl;
    cout << "interact_obj::arg value @ start = " << arg << endl << endl;
    vis::print_obj(arg, "arg");

    cout << "Adding one to arg " << endl;
    arg += 1;

    cout << "interact_obj::arg value @ end = " << arg << endl << endl;
    vis::print_obj(arg, "arg");

    cout << endl << "exiting interact_obj" << endl;
    cout << "=============================================" << endl;
}