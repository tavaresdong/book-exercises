#include <iostream>

using namespace std;

/*
 * 16.42
 * template <typename T> void g(T&& val);
 * int i = 0; const in ci = i;
 * g(i) -> int& g(ci) -> const int& g(i * ci) -> int
 */

// 16.43
// g(i = ci) -> int& because i = ci returns lvalue reference of i

// 16.44
// (1) if g(T val):
// g(i) -> int g(ci) -> const int g(i * ci) -> int
// (2) if g(const T&):
// g(i) -> int g(ci) -> int g(i * ci) -> int

// template <typename T> void g(T&& val) { vector<T> v; }
// call g(42) what will happen?
// T will be deduced as int
// what if we call g(i) while i is an int
// then T will be deduced int&, we cannot create a vector of references.
// because references are not assignable
