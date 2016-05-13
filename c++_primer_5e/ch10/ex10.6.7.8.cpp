#include <iostream>
#include <algorithm>
using namespace std;

void outputVec(const vector<int>& vec) {
    for (auto& val : vec) {
        cout << val << " " ;
    }
    cout << endl;
}

int main(int argc, char **argv) {
    vector<int> vec{1, 2, 3, 4, 5};
    outputVec(vec);
    fill_n(vec.begin(), vec.size(), 0);
    outputVec(vec);

    return 0;
}

// 10.7
// (a) copy(lst.cbegin(), lst.cend(), back_inserter(vec));
// (b) ok

// Because it's not the algorithm that mutates the container
// It's the iterator that mutates the container
