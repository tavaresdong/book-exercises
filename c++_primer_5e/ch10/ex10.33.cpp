#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
    ifstream in("ex10.33.txt");
    ofstream oddOut("ex10.33.odd.out");
    ofstream evenOut("ex10.33.even.out");
    istream_iterator<int> inIter(in);
    istream_iterator<int> eof;
    ostream_iterator<int> oddOutIter(oddOut, "\n");
    ostream_iterator<int> evenOutIter(evenOut, "\n");

    vector<int> vec(inIter, eof);
    copy_if(vec.begin(), vec.end(), evenOutIter, 
                    [](int v) { return v % 2 == 0; });
    copy_if(vec.begin(), vec.end(), oddOutIter,
                    [](int v) { return v % 2 != 0; });
    return 0;
}
