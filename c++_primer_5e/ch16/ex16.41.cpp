#include <iostream>

using namespace std;

template <typename T1, typename T2>
auto mysum(T1 val1, T2 val2) -> decltype(val1 + val2)
{
    return val1 + val2;
}

int main(int argc, char **argv)
{
    auto val = mysum(2, 3.4);
    cout << val << endl;
}
