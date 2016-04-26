#include <iostream>
#include <memory>

using namespace std;

// In my compiler (G++ 4.8.4)
// the assignment operator and copy constructor are =delete 
int main(int argc, char **argv) {
    unique_ptr<int> u1(new int(23));
    unique_ptr<int> u2 = u1;
    unique_ptr<int> u3;
    u3 = u1;
    unique_ptr<int> u4(u1);
    return 0;
}
