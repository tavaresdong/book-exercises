#include <iostream>
#include <memory>

using namespace std;

// The original memory is freed, the value there is undefined
// and there is a double free error

void process(shared_ptr<int> p) {
    *p += 1;
    cout << p.use_count() << endl;
}

int main(int argc, char **argv) {
    shared_ptr<int> p(new int(42));
    cout << p.use_count() << endl;
    process(shared_ptr<int>(p.get()));
    cout << p.use_count() << endl;
    return 0;
}
