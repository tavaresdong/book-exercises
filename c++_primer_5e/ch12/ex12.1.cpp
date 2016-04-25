#include "StrBlob.h"
#include <algorithm>
#include <iostream>

using namespace std;
int main(int argc, char** argv) {
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
    }

    // b2 is dead
    // b1 has 4 elements
    for_each(b1.begin(), b1.end(), [] (const string& str) { cout << str << " ";});
    cout << endl;
    return 0;
}
