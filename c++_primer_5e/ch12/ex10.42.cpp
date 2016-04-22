#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

void elimDups(list<string> &words) {
    words.sort();
    words.unique();
}

int main(int argc, char **argv) {
    list<string> lst{"good", "bad", "sad", "bad", "happy", "terrible", "terrible"};
    elimDups(lst);
    for_each(lst.begin(), lst.end(), [] (const string& str) { cout << str << endl;});
    return 0;
}
