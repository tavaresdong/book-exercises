#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    istream_iterator<int> in_iter(cin);
    istream_iterator<int> eof;
    ostream_iterator<int> out_iter(cout, " ");
    vector<int> vec(in_iter, eof);
    sort(vec.begin(), vec.end());
    copy(vec.begin(), vec.end(), out_iter);
    return 0;
}
