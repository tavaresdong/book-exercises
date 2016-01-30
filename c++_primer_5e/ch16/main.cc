#include "function.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    std::string str1("good"), str2("day");
    std::cout << compare(2, 3) << compare(str1, str2) << std::endl;

    vector<int> vecint{1, 2, 3, 4, 5, 7};
    vector<string> vecstr{"good", "bad", "sad", "happy"};
    cout << find(vecint.begin(), vecint.end(), 6) << find(vecstr.begin(), vecstr.end(), "sad") << endl;
    return 0;
}
