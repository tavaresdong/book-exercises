#include <iostream>

using namespace std;

class DebugDelete {
    template <class T>
    void operator () (T* ptr) const {
        cout << "Deleting the pointer" << endl;
        delete ptr;
    }
};


