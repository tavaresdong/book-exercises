#include "String.h"
#include <cstring>
#include <algorithm>


String::String()
{
    auto beg = alloc.allocate(1);
    *beg = '\0';
    first = beg;
    last = first + 1;
}

String::String(const char* cstr)
{
    size_t len = std::strlen(cstr) + 1;
    auto beg = alloc.allocate(len);
    std::strncpy(beg, cstr, len);
    first = beg;
    last = beg + len;
}

std::ostream& operator << (std::ostream& out, const String &str)
{
    std::for_each(str.first, str.last,
        [&out](const char& c) { out << c; });
    return out;
}
