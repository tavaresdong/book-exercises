#include <iostream>
#include <memory>

using namespace std;

// 12.18 why shared_ptr don't have release member?
// because other shared_ptr may still delete this pointer
// so it's meaningless to define release 

int main(int argc, char **argv) {
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef unique_ptr<int> IntP;

    // IntP p0(ix);  Illegal
    // IntP p1(pi); OK, but it will auto-release pi, and cause error(not newed int)
    // IntP p2(pi2);  OK, but will auto-release
    // IntP p3(&ix); same as (2)
    // IntP p4(new int(2048)); OK
    // IntP p5(p2.get()); Ok but may cause double-free error
}
