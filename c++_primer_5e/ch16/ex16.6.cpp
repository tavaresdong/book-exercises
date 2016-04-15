#include <iostream>
#include <algorithm>

using namespace std;

template <class T, unsigned N>
T* myBegin(const T (&arr) [N]) {
    return &arr[0];
}

template <class T, unsigned N>
T* myEnd(const T (&arr) [N]) {
    return &arr[N];
}

int main(int argc, char **argv) {
    int a[5] = {1, 2, 1, 4, 1};
    cout << count(begin(a), end(a), 1) << endl;
    return 0;
}
