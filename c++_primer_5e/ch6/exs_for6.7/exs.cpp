#include <iostream>
#include <vector>

using namespace std;

int multiply(int a, int b) {return a * b;}
int add(int a, int b) {return a + b;}
int subtract(int a, int b) {return a - b;}

int main(int argc, char **argv)
{
    vector<decltype(multiply) *> vec = {multiply, add, subtract};

    for (auto f : vec)
        cout << f(2, 2) << endl;
}
