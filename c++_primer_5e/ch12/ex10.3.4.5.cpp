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
    char c1[10] = "test10";
    char c2[10] = "test10";
    vector<char *> cv1{c1};
    vector<char *> cv2{c2};
    vector<string> sv1 = {"good", "bad"};
    vector<string> sv2 = {"good", "bad"};

    cout << accumulate(begin(v), end(v), 0) << endl;
    cout << accumulate(dv.cbegin(), dv.cend(), 0) << endl;
    cout << accumulate(dv.cbegin(), dv.cend(), 0.0) << endl;

    // Not the same, std::equal uses addresses to compare
    // we need to use strcmp/strncmp to compare two c-style strings
    cout << equal(begin(cv1), end(cv1), begin(cv2)) << endl;
    cout << equal(begin(sv1), end(sv1), begin(sv2)) << endl;
    return 0;
}
