#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    const int v2 = 0;
    int v1 = v2;
    int *p = &v1,  &r1 = v1;

    r1 = v2;
    cout << v2 << endl;
    return 0;
}
