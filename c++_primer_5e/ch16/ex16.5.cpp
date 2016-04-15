#include <iostream>

using namespace std;

template <typename T, unsigned N>
void myPrint(const T (&arr) [N]) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(int argc, char **argv) {
    int a[5] = {1, 2, 3, 4, 5};
    double b[4] = {1.1, 2.2, 3.3, 4.4};
    myPrint(a);
    myPrint(b);
    return 0;
}
