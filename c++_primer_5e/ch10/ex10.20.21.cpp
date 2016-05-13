#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
    vector<string> vec{"good", "bad", "terrific", "sad", "happy"};

    cout << count_if(vec.begin(), vec.end(), 
                    [](const string& str)
                    { return str.size() >= 4; }) << endl;
    int v = 10;
    auto f = [v]() mutable -> bool 
    { if (v == 0) return false; else { --v; return true; } };

    while (f()) {
        cout << "Not Zero" << endl;
    }
    cout << "Zero" << endl;
    return 0;
}
