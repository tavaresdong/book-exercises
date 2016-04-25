#include <memory>

using namespace std;

int main(int argc, char** argv) {
    int *q = new int(42); // Dynamically allocates an integer with value 42
    int *r = new int(100); // 100
    r = q; // Memory leak!
    auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
    r2 = q2;// the previous memory associated with r2 is freed
    return 0;
}
