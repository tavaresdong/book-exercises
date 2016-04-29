#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int size = 20;
    char *arr = new char[size + 1];
    cin.ignore();
    cin.get(arr, size + 1);

    cout << arr << endl;
    delete [] arr;
    return 0;
}
