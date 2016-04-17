#include <iostream>
#include <vector>

using namespace std;

// 16.40 ok only when type supports + operation
// and return type depends on the return type of + operation

class Foo {
public:
    Foo() : val(0) {}
    void incr() { val += 1; }
    void output() { cout << val << endl; }
private:
    int val;
};

Foo operator + (Foo lhs, int) {
    return lhs;
}

template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
    return *beg;
}

int main(int argc, char **argv) {
    vector<Foo> vfoo(1);
    auto ret = fcn3(vfoo.begin(), vfoo.end());
    ret.incr();
    // Prove the returned value is not a reference!
    vfoo.at(0).output();
    ret.output();
    return 0;
}
