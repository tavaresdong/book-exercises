#include <iostream>
using namespace std;

template <typename T>
string debug_rep(const T& t)
{
    cout << "const T&" << endl;
}

template <typename T>
string debug_rep(T* p)
{
    cout << "T*" << endl;
}

// Non-template version 
string debug_rep(int *t)
{
    cout << "int *" << endl;
}

string debug_rep(char *t)
{
    cout << "char *" << endl;
}

string debug_rep(const char* t)
{
    cout << "const char*" << endl;
}

int main(int argc, char **argv)
{
    int i = 0;
    char c = 'a';
    debug_rep(&i);
    debug_rep(&c);
    debug_rep("hi");
    return 0;
}


// 16.49
// template <typename T> void f(T);
// template <typename T> void f(const T*);
// template <typename T> void g(T);
// template <typename T> void g(T*);
// int i = 42, *p = &i;
// const int ci = 0m *p2 = &ci
// g(42) -> initialize g(T) with T as int
// g(p)  -> initialize g(T*) with T as int
// g(ci) -> initialize g(T) with T as const int
// g(p2) -> initialize g(T*) with T as const int
// f(42) -> initialize f(T) with T as int
// f(p)  -> initialize f(T) with T as int*
// f(ci) -> initialize f(T) with T as const int
// f(p2) -> initialize f(const T*) with T as int
