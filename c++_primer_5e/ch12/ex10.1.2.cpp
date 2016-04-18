#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main(int argc, char **argv) {
    vector<int> v = {1, 2, 3, 4, 2, 4, 2, 5, 2};
    list<string> l = {"hi", "day", "day", "dau"};
    cout << count(begin(v), end(v), 2) << endl;
    cout << count(begin(l), end(l), "day") << endl;
    return 0;
}
