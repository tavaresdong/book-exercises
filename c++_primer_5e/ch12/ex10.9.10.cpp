#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void elimDups(vector<T>& vec) {
    sort(vec.begin(), vec.end());
    auto uni = unique(vec.begin(), vec.end());
    vec.erase(uni, vec.end());
}

template <typename Iter>
void output(Iter beg, Iter end) {
    while (beg != end) {
        cout << *beg << " ";
        beg ++;
    }
    cout << endl;
}

int main(int argc, char **argv) {

    vector<int> vec{1, 2, 3, 1, 4, 2, 5, 3};
    output(vec.begin(), vec.end());
    elimDups(vec);
    output(vec.begin(), vec.end());
    
    return 0;
}
