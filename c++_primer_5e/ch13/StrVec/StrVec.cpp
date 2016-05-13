#include "StrVec.h"
#include <algorithm>

using std::string;
using std::uninitialized_copy;
using std::for_each;

void StrVec::push_back(const string& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<string*, string*>
StrVec::alloc_n_copy(const string* b, const string* e)
{
    auto data = alloc.allocate(e - b);

    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    // need to capture this
    for_each(begin(), end(), 
        [this](string& str){ alloc.destroy(&str); });

    // for (auto p = first_free; p != elements;)
    //     alloc.destroy(--first_free);
    alloc.deallocate(elements, size());
}

StrVec::StrVec(const StrVec &s)
{
    auto pr = alloc_n_copy(s.begin(), s.end());
    elements = pr.first;
    first_free = cap = pr.second;
}

StrVec& StrVec::operator=(StrVec &&rh) noexcept
{
    if (this != &rh)
    {
        free();
        elements = rh.elements;
        first_free = rh.first_free;
        cap = rh.cap;
        rh.elements = rh.first_free = rh.cap = nullptr;
    }
    return *this;
}

StrVec::StrVec(StrVec &&rh) noexcept 
  : elements(rh.elements), first_free(rh.first_free), cap(rh.cap)
{
    rh.elements = rh.first_free = rh.cap = nullptr;
}

StrVec& StrVec::operator=(const StrVec &s)
{
    auto pr = alloc_n_copy(s.begin(), s.end());
    free();
    elements = pr.first;
    first_free = cap = pr.second;
    return *this;
}

StrVec::~StrVec()
{
    free();
}

void StrVec::reallocate()
{
    auto new_capacity = size() ? 2 * size() : 1;

    auto new_data = alloc.allocate(new_capacity);

    auto dest = new_data;
    auto elem = elements;

    // use move constructor for std::string
    // more efficient
    for (size_t i = 0; i != size(); ++i)
    {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = new_data;
    first_free = dest;
    cap = elements + new_capacity;
}