#include <iostream>
#include <exception>
#include "ex12.19.h"

using namespace std;

int main(int argc, char **argv) {
    string input;
    StrBlob blob;
    while (cin >> input) {
        blob.push_back(input);
    }

    auto bp = blob.begin();
    try {
        while (true) {
            cout << bp.deref() << endl;
            bp.incr();
        }
    } catch (exception e) {
        e.what();
    }
    return 0;
}
