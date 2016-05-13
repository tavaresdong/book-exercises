#ifndef _STRING_H_
#define _STRING_H_

#include <memory>
#include <iostream>

class String {
public:
    String();
    String(const char*);
    size_t size() const { return last - first; }
    friend std::ostream& operator << (std::ostream& out, const String &str);
private:
    std::allocator<char> alloc;
    char* first;
    char* last;
};

#endif
