#include <iostream>
#include <utility>

template <typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2) {
    f(std::forward<T2>(t2), std::forward<T1>(t1));
    // expected 4 5
    std::cout << t1 << t2 << std::endl;
}

void f1(int &&v1, int &v2) {
    v1 ++;
    v2 ++;
    // expected:5 4
    std::cout << v1 << " " <<  v2 << std::endl;
}


int main(int argc, char ** argv) {
    int i = 3;

    // 4 5 expected
    flip(f1, i, 4);

    return 0;
}
