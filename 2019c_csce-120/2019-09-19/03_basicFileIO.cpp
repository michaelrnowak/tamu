#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

int main()
{

    ifstream ifs{"test1.dat"}; // "test1.dat is file to bind to input stream.
    // no need to explicitly call open on file
    if (!ifs.is_open()) { // check if file is open; if not, print msg and exit
        cout << "Can't find the file" << endl;
        return 1;
    }

    // remove header from file (assumes not more than 80 characters in length)
    char firstLine[80];
    ifs.getline(firstLine, 80);
    cout << firstLine << endl;

    /* This is one way to read ints, however, there can be chars
    * left in the stream (even invisible ones), which makes this
    * an inconvenient way to parse a file.
    */

    // while (!ifs.eof()) {
    //     int i; ifs >> i;
    //     cout << "i = " << i << endl;
    // }

    /* Here is a better way to read ints: while there can be chars
     * left in the stream (even invisible ones),this approach
     * handles those chars as long as we know the format of the input!
     * If the ints are space delimited, we can jump to the next
     * space and begin reading (ifs will ignore whitespace);
     * tab delimited, jump to the next tab and begin reading;
     * space delimited, jump to the next space and begin reading.
     */

    while (!ifs.eof()) {
        int i = 0; ifs >> i;
        if (ifs.bad()) {
            return 1;
        } else if (ifs.fail()) {
            ifs.clear();
            ifs.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cout << i << endl;
        }
    }

    /* Can combine checks
     *   if (ifs.fail() && !ifs.eof()) { // when might this be useful?
     *      // do something
     *   }
     *
     *  if (ifs.fail() && ifs.eof()) { // when might this be useful?
     *       // do something
     *  }
     */

    /* We can also read a file line-by-line */

    // const int max = 255;
    // char line[max];
    // while (ifs.getline(line, max)) {
    //     cout << line << endl;
    // }

    /* We've talked about reading from a file.  What about writing to one? */

    // // ofstream ofs{"out.dat"}; // if file exists, it is overwritten
    // ofstream ofs{"out.dat", ios_base::app}; // if file exists, append to it
    // ofs << "Hello, world!"; // Writes string "Hello, world!" to the file "out.dat"

    return 0;
}