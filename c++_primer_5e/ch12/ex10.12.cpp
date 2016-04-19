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

template <unsigned N>
bool hasAtLeastSize(const string& str) {
    return str.size() >= N;
}

int main(int argc, char **argv) {

    vector<string> vec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(vec);
    auto iter = partition(vec.begin(), vec.end(), hasAtLeastSize<5>);
    output(vec.begin(), iter);
    return 0;
}
