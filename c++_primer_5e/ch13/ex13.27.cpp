#include <iostream>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string())
            : ps(new std::string(s)), i(0), size(new size_t(1)) {}
    HasPtr(const HasPtr& other) : ps(other.ps), i(other.i), size(other.size) 
    {
        *size += 1;
    }
    void print() { std::cout << *ps << " " << i << *size << std::endl; }
    HasPtr& operator=(HasPtr& rh) {
        *rh.size += 1;
        if (--*size == 0) {
            delete ps;
            delete size;
        }
        ps = rh.ps;
        i = rh.i;
        return *this;
    }
    ~HasPtr() {
        if (--*size == 0) {
            delete ps;
            delete size; 
        }
    }
private:
    std::string *ps;
    int i;
    size_t* size;
};


int main(int argc, char **argv) {
    HasPtr ptr1("Dirk");
    ptr1.print();
    HasPtr ptr2 = ptr1;
    ptr2.print();
    HasPtr ptr3("Tim");
    ptr2 = ptr3;
    ptr1.print();

    return 0;
}
