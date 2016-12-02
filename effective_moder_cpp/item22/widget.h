#ifndef WIDGET_H_
#define WIDGET_H_
#include <memory>

// The pimpl idiom is to reduce dependency between clients of Widget and 
// Implementation details: vector string ...
// Also note unique_ptr is move-only type, compiler won't generate 
// Copy operations for us, and even if they do, it's shallow copy
class Widget
{
public:
    Widget();
    
    // We must have Destructor defined in .cc and after the definition of Impl
    // So we must declare here and define later
    // Because the destruction needs to see the definition of Impl during compilation 
    ~Widget();

    // And also, Item 17 suggests that declaration of destructor will
    // Prevent the compiler from generation move operations for you
    // So we need to do it by ourselves
    // And also, compiler generated move need to destroy pImpl before re-assign it
    // So We also need to declare but not define:
    Widget(Widget&& rhs);
    Widget& operator = (Widget&& rhs);

    Widget(const Widget& rhs);
    Widget& operator = (const Widget& rhs);

private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};

#endif
