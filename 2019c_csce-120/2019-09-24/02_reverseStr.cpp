#include <iostream>
#include "../utilities/PrintVisualV2.h"

using namespace std;

int my_strlen(const char *);
void reverseStr(char *);

int main()
{
    // "Texas" --> "saxeT"
    char s[] = "Texas";
    cout << s << endl;
    vis::print(s);
    cout << "Length of s : " << my_strlen(s) << endl;

    reverseStr(s);
    cout << s << endl;
    vis::print(s);

    return 0;
}

int my_strlen(const char *str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; ++i)
        len += 1;
    return len;
}

void reverseStr(char *str)
{
    int len = my_strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}