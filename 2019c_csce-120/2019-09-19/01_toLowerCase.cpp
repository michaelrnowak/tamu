#include <iostream>
#include "/Users/michael/src/cxx-printvisual/PrintVisualV2.h"

using namespace std;

char getLowerChar(char);
void toLowerCase(char *);

int main()
{

    char question[] = "HOW/WHY DOES THIS STRING BECOME LOWERCASE AFTER CALL TOLOWERCASE?";
    cout << question << endl;
    toLowerCase(question);
    cout << question << endl;

    return 0;
}

char getLowerChar(char c)
{
    /* A useful check to ensure that our function has well defined behavior
     * given any input c; we will only return a value if it is actually an
     * upper-case character.
     */
    if ((c >= 'A') && (c <= 'Z'))
        return (c - 'A') + 'a';
}
void toLowerCase(char *str) // semantics of argument passing are same as initialization
{
    for (int i = 0; str[i] != '\0'; ++i)
        str[i] = getLowerChar(str[i]);
}