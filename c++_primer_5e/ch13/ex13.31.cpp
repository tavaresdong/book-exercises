#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using std::vector;

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr& other) : ps(new std::string(*other.ps)), i(other.i) 
    { }
    void setPs(std::string* nps) { delete ps; ps = nps; }
    void print() const { std::cout << *ps << " " << i << std::endl; }
    HasPtr& operator=(HasPtr rh) {
        swap(*this, rh);
        return *this;
    }
    ~HasPtr() { delete ps; }
    friend void swap(HasPtr& lh, HasPtr& rh);
    friend bool operator < (const HasPtr& lh, const HasPtr& rh);
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

bool operator < (const HasPtr& lh, const HasPtr& rh) {
    return *lh.ps < *rh.ps;
}


int main(int argc, char **argv) {
    vector<HasPtr> vec {HasPtr("good"),
                        HasPtr("days"),
                        HasPtr("happy"),
                        HasPtr("bird")};
    std::sort(vec.begin(), vec.end());
    std::for_each(vec.begin(), vec.end(), 
                  [](const HasPtr& p) { p.print(); });
}
