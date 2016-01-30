#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <iostream>

template <typename T>
int compare(const T& v1, const T& v2)
{
    if (v1 < v2) return -1;
    else if (v2 < v1) return 1;
    else return 0;
}

template <typename Iter, typename Value>
bool find(Iter begin, Iter end, Value v)
{
    for (; begin != end; begin++) {
        if (*begin == v) return true;
    }

    return false;
}

template <typename T, unsigned Dim>
void print(T (&arr)[Dim])
{
    for (auto &elem : arr)
        std::cout << elem << " ";
    std::cout << std::endl;
}

#endif
