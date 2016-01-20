#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int i = 0, &r = i;
    const int ci = i, &cr = ci;
    
    auto a = r;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto &g = ci;

    a = 42; b = 42; c = 42;
    d = 42; e = 42; g = 42;

    cout << a << " " << b << " " << c
         << " " << d << " " << e << " "
         << g << endl;
    return 0;
}
