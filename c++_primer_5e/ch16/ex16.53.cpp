#include <iostream>

template <typename T>
std::ostream& print(std::ostream& os, const T& t)
{
    return os << t;
}

template <typename T, typename ...Args>
std::ostream& print(std::ostream& os, const T& t, const Args& ... rest)
{
    os << t;
    print(os, rest...);
}

int main()
{
    print(std::cout, 1, 3, "good", "hi", 2.3) << "end";
}
