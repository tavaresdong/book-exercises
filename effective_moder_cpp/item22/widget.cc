#include "widget.h"
#include <string>
#include <vector>

struct Widget::Impl
{
    std::string str;
    std::vector<int> vec;
};

Widget::Widget()
: pImpl(std::make_unique<Impl>())
{}

// We can use default implementation
Widget::~Widget() = default;

// Also, after the definition of Impl
Widget::Widget(Widget&& rhs) = default;
Widget& Widget::operator = (Widget&& rhs) = default;

Widget::Widget(const Widget& rhs) : pImpl(std::make_unique<Impl>(*rhs.pImpl))
{}

Widget& Widget::operator = (const Widget& rhs)
{
    *pImpl = *rhs.pImpl;
    return *this;
}
