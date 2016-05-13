#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

using namespace std;


int main(int argc, char** argv) {
    vector<int> vec{1, 2, 3, 1, 2, 4, 5, 4, 6};
    sort(vec.begin(), vec.end());
    list<int> lst;
    unique_copy(vec.begin(), vec.end(),
                    inserter(lst, lst.begin()),
                    [](int v1, int v2){ return v1 == v2; });
    for_each(lst.begin(), lst.end(),
             [](int v) { cout << v << endl; });
    return 0;
}
