#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
int compare(const T& v1, const T& v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

int main(int argc, char **argv) {
    // 16.37
    int realmax = max<int>(2.3, 1);
    cout << realmax << endl;

    // 16.38 make_shared use the type to initialize an object
    // by passing arguments to this type's constructor
   
    // 16.39
    auto res = compare<string>("good", "day");
    cout << res << endl;
    return 0;
}
