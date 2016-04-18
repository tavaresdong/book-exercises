#include <iostream>
#include <algorithm>

using namespace std;

// 10.4
// vector<double> v = {1.1, 1.2}
// what's wrong with calling accumulate(v.cbegin(), v.cend(), 0)?
// No problem with compiling, but the result will be of int type

int main(int argc, char **argv) {
    vector<int> v = {1, 2, 3, 4, 5};
    vector<double> dv = {1.1, 2.2, 3.3};
    cout << accumulate(begin(v), end(v), 0) << endl;
    cout << accumulate(dv.cbegin(), dv.cend(), 0) << endl;
    cout << accumulate(dv.cbegin(), dv.cend(), 0.0) << endl;
    return 0;
}
