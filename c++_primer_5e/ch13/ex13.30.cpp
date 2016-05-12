#include <iostream>
#include <utility>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr& other) : ps(new std::string(*other.ps)), i(other.i) 
    { std::cout << "copying" << *ps << std::endl; }
    void setPs(std::string* nps) { delete ps; ps = nps; }
    void print() { std::cout << *ps << " " << i << std::endl; }
    HasPtr& operator=(HasPtr rh) {
        swap(*this, rh);
        return *this;
    }
    ~HasPtr() { std::cout << "destructing" << *ps << std::endl; delete ps; }
    friend void swap(HasPtr& lh, HasPtr& rh);
private:
    std::string *ps;
    int i;
};

void swap(HasPtr& lh, HasPtr& rh) {
    using std::swap;
    std::cout << "Swapping two HasPtrs" << std::endl;
    swap(lh.ps, rh.ps);
    swap(lh.i, rh.i);
}


int main(int argc, char **argv) {
    HasPtr ptr1("good");
    HasPtr ptr2("day");
    ptr2 = ptr1;
    return 0;
}
