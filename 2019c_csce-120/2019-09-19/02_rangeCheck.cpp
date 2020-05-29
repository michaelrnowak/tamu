/**********************

This program continuously requests that user enter an integer to
standard input, until that integer is within [minVal, maxVal].

**********************/

#include <iostream> // input and output library, includes cin and cout
#include <limits>

using namespace std; // so we do not have to prepend std:: to everything

const int minVal = 5000;
const int maxVal = 10000;

int main() // function were execution begins
{
    int valRead = 0;

    do  {
        cout << "Enter a value between " << minVal << " and " << maxVal << " please... ";
        cin >> valRead;

        /*
         * Check whether we've encountered an unrecoverable error (stream corrupt, etc.); if so,
         * I elect to exit the program.  What ultimately will likely depend on requirements.
         */

        if (cin.bad()) //
            return 1;

        /*
         * check whether the stream is in the bad or fail state (.fail() checks both);
         * we just checked bad on its own, so if we get in here, must be in fail state.
         */
        if (cin.fail()) {
            /*
             * reset the stream state to good with clear()
             */
            cin.clear();
            /*
             * ignore character "latched on to" and any others through the max size of the
             * stream or until the we reach the '\n' character (whichever one comes first)
             * with ignore().  Note: depending on the format of the input, we may choose to
             * ignore until we reach the '\t', ' ', ';', or some other character.  Therefore,
             * the second argument to ignore will not always be '\n'; instead, it will
             * be dependent on the format of the input.
             */
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (valRead < minVal || valRead > maxVal);

    cout << "I read : " << valRead << endl;

    return 0; // return zero from main() to indicate success
}