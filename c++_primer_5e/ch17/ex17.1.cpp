#include <iostream>
#include <tuple>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    tuple<int, int, int> t1 (10, 20, 30);
    tuple<string, vector<string>, pair<string, int> > t2 ("good", {"day",
    "job"}, {"jim", 23} );

    auto name = get<2>(t2).first;
    cout << name << endl;
}
