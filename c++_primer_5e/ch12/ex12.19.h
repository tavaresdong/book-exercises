#ifndef _EX1219_
#define _EX1219_
#include <vector>
#include <memory>
#include <stdexcept>
#include <initializer_list>
using namespace std;

class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob {
public:
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
    typedef vector<string>::size_type size_type;
    StrBlob() : data(make_shared<vector<string>>()) {}
    StrBlob(std::initializer_list<std::string> il) :
            data(make_shared<vector<string>>(il)) {}
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &t) {
        data->push_back(t); 
    }
    void pop_back() {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }

    StrBlobPtr begin();
    StrBlobPtr end();
    ConstStrBlobPtr begin() const;
    ConstStrBlobPtr end() const;

    std::string& front();
    const std::string& front() const;
    std::string& back();
    const std::string& back() const;
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const {
        if (i >= data->size()) throw std::out_of_range(msg);
    }
};


class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    string& deref() const {
        auto sp = check(curr, "dereference past end");
        return (*sp)[curr];
    }

    StrBlobPtr& incr() {
        check(curr, "Increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
private:
    std::shared_ptr<vector<string>> check(size_t i, const string& msg) const {
        auto ret = wptr.lock();
        if (!ret) throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size()) throw std::out_of_range(msg);
        return ret;
    }

    std::weak_ptr<vector<string>> wptr;
    size_t curr;
};


class ConstStrBlobPtr {
public:
    ConstStrBlobPtr() : curr(0) {}
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    const string& deref() const {
        auto sp = check(curr, "dereference past end");
        return (*sp)[curr];
    }

    ConstStrBlobPtr& incr() {
        check(curr, "Increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
private:
    std::shared_ptr<vector<string>> check(size_t i, const string& msg) const {
        auto ret = wptr.lock();
        if (!ret) throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size()) throw std::out_of_range(msg);
        return ret;
    }

    std::weak_ptr<vector<string>> wptr;
    size_t curr;
};
#endif
