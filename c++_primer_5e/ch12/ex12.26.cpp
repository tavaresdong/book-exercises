#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char **argv) {
    int size = 20;
    allocator<char> all;
    auto arr = all.allocate(size + 1);
    cin.ignore();
    cin.get(arr, size + 1);
    cout << arr << endl;
    return 0;
}
