#include <iostream>

using namespace std;

template <class T, unsigned N>
constexpr int arraysize(const T (&arr) [N]) { return N; }

int main(int argc, char **argv) {
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[arraysize(arr1) - 1] = {1, 2, 3, 4};

    return 0;
}
