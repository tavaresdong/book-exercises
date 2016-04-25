#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;

shared_ptr<vector<int>> create_vector() {
    return make_shared<vector<int>>();
}

void read_input(shared_ptr<vector<int>> vec) {
    int val;
    while (cin >> val) {
        vec->push_back(val);
    }
}

void print_vec(shared_ptr<vector<int>> vec) {
    for_each(vec->begin(), vec->end(),
             [] (int v) { cout << v << " "; });
    cout << endl;
}

int main(int argc, char **argv) {
    auto vp = create_vector();
    read_input(vp);
    print_vec(vp);
    return 0;
}
