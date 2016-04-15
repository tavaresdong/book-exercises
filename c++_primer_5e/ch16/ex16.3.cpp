#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

template <typename Iter, typename T>
bool myFind(Iter beg, Iter end, T value) {
    while (beg != end) {
        if (*beg == value)
            return true;       
        beg = next(beg);
    }
    return false;
}

int main(int argc, char **argv) {
    list<int> l = {1, 2, 3};
    vector<string> v = {"good", "bye"};
    cout << myFind(l.begin(), l.end(), 2) << endl;
    cout << myFind(v.begin(), v.end(), "bye") << endl;
    cout << myFind(v.begin(), v.end(), "ghah") << endl;
    return 0;
}
