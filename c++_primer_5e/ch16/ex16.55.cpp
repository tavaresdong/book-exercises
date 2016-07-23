#include <iostream>


template <typename T, typename ...Args>
std::ostream& print(std::ostream& os, const T& t, const Args& ... rest)
{
    os << t;
    print(os, rest...);
}

// Error! this is put after the variadic template version
// so when compiling, cannot find version print(ostream&), Fail!
template <typename T>
std::ostream& print(std::ostream& os, const T& t)
{
    return os << t;
}

int main()
{
    print(std::cout, 1, 3, "good", "hi", 2.3) << "end";
}
