#include "TextQuery.h"

using namespace std;

int main(int argc, char **argv) {
    ifstream infile("test.txt");
    TextQuery tq(infile);
    string s;
    cin >> s;
    print(cout, tq.query(s)) << endl;

}
