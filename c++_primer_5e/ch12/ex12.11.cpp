#include <iostream>
#include <memory>

using namespace std;

// The original memory is freed, the value there is undefined
// and there is a double free error

void process(shared_ptr<int> p) {
}

int main(int argc, char **argv) {
    shared_ptr<int> p(new int(42));
    process(shared_ptr<int>(p.get()));
    return 0;
}
