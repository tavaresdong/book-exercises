#include <iostream>
#include <utility>

using namespace std;

class X {};

void inner(const X&) { cout << "inner(const T&)" << endl; }
void inner(X&&) { cout << "inner(T&&)" << endl; }

template <typename T>
void outer(T&& t) { inner(std::forward<T>(t)); }

// std::forward is better used together with T&& template
// parameters.
// see source code of std::forward

int main(int argc, char **argv) {
    X a;
    X b = a;
    outer(a); // forward an lvalue
    outer(X());
    inner(std::forward<X>(X()));
    inner(std::forward<X&>(b)); // forward an lvalue
}
