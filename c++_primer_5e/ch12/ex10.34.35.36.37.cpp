#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

using namespace std;

int main(int argc, char **argv) {
    vector<int> vec{0, 1, 2, 0, 3, 4};
    vector<int> tenEle{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list<int> lst;

    // 10.34
    for_each(vec.crbegin(), vec.crend(), 
                    [](int v) { cout << v << " "; });
    cout << endl;
    
    // 10.35 print elements in reverse order using ordinary iters
    for (auto iter = prev(vec.end());
         iter != prev(vec.begin()); --iter) {
        cout << *iter << " ";
    }
    cout << endl;

    auto pos = find(vec.rbegin(), vec.rend(), 0);
    // 10.36 Expect : 4
    cout << "Pos : " << pos.base() - vec.begin() << endl;

    // 10.37 copy elements 3 through 7 in reverse order to a list
    auto iter7 = tenEle.rbegin();
    auto iter3 = tenEle.rbegin();
    for (int i = 0; i < 3; i++) { iter7 = next(iter7); }
    for (int i = 0; i < 8; i++) { iter3 = next(iter3); }
    copy(iter7, iter3, back_inserter(lst));

    for_each(lst.begin(), lst.end(),
                    [](int v) { cout << v << " "; });
    cout << endl;

    return 0;
}
