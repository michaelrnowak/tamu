#include <iostream>
#include <sstream>

using namespace std;

int countWords(std::string str)
{
    stringstream ss{str};
    int count = 0; std::string tmp;
    while (ss >> tmp)
        count += 1;
    return count;
}

int main()
{
    int count = countWords("The IEEE does not require individuals working on a thesis to obtain a formal reuse license, however, you may print out this statement to be used as a permission grant.");
    cout << count << endl;

    return 0;
}