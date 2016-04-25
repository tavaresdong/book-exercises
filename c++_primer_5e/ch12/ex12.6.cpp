#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int>* create_vector() {
    return new vector<int>();
}

void read_input(vector<int>* vec) {
    int val;
    while (cin >> val) {
        vec->push_back(val);
    }
}

void print_vec(vector<int>* vec) {
    for_each(vec->begin(), vec->end(),
             [] (int v) { cout << v << " "; });
    cout << endl;
}

int main(int argc, char **argv) {
    auto vp = create_vector();
    read_input(vp);
    print_vec(vp);
    delete vp;
    return 0;
}
