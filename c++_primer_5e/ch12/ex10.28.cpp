#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int main(int argc, char** argv) {
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};

    // vectors cannot call push_front!
    vector<int> v2, v4;
    list<int> lst;
    copy(vec.begin(), vec.end(), back_inserter(v2));
    copy(vec.begin(), vec.end(), front_inserter(lst));
    copy(vec.begin(), vec.end(), inserter(v4, v4.begin()));

    // Should be 1 2 3 ... 9
    for_each(v2.begin(), v2.end(),
                    [](int v) { cout << v << " ";});
    cout << endl;

    // Should be 9 8 ... 1
    for_each(lst.begin(), lst.end(),
                    [](int v) { cout << v << " ";});
    cout << endl;

    // Should be 1 2 ... 9
    for_each(v4.begin(), v4.end(),
                    [](int v) { cout << v << " ";});
    cout << endl;
    return 0;
}
