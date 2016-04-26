#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char **argv) {
    auto sp = make_shared<int>();
    auto p = sp.get();
    delete p;
    // Double delete!
}
