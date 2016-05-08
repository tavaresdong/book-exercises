#include <iostream>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr& other) : ps(new std::string(*other.ps)), i(other.i) {}
    void setPs(std::string* nps) { delete ps; ps = nps; }
    void print() { std::cout << *ps << " " << i << std::endl; }
private:
    std::string *ps;
    int i;
};


int main(int argc, char **argv) {
    HasPtr ptr1("good");
    HasPtr ptr2 = ptr1;
    std::string* str2 = new std::string("happy");
    ptr2.setPs(str2);
    ptr1.print();
    ptr2.print();

    return 0;
}
