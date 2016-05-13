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

String::String(const String& str)
{
    std::cout << "Copying a String" << std::endl;
    auto beg = alloc.allocate(str.size());
    std::strncpy(beg, str.first, str.size());
    first = beg;
    last = beg + str.size();
}

String& String::operator=(const String& str)
{
    std::cout << "assignment operator of String called" << std::endl;
    auto beg = alloc.allocate(str.size());
    std::strncpy(beg, str.first, str.size());
    free();
    first = beg;
    last = beg + str.size();
    return *this;
}

void String::free()
{
    // Maybe not necessary
    std::for_each(first, last,
        [this] (char &c) { alloc.destroy(&c); });
    alloc.deallocate(first, last - first);
}

String::~String()
{
    free();
}
