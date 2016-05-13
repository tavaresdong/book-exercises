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

bool isShorter(const string& str1, const string& str2) {
    return str1.size() < str2.size();
}

int main(int argc, char **argv) {

    vector<string> vec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(vec);
    stable_sort(vec.begin(), vec.end(), isShorter);
    output(vec.begin(), vec.end());
    return 0;
}
