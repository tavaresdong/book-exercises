#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    ifstream in("ex10.29.txt");
    istream_iterator<string> in_iter(in);
    istream_iterator<string> eof;
    ostream_iterator<string> out_iter(cout, " ");
    vector<string> vec(in_iter, eof);
    copy(vec.begin(), vec.end(), out_iter);
    return 0;
}
