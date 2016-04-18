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
