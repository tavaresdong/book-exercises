#include <memory>
#include <iostream>

class Foo : public std::enable_shared_from_this<Foo>
{
    // Make constructors private
    Foo();
    Foo(int i) : val(i) { }
public:
    template <typename ... T>
    static std::shared_ptr<Foo> create(T&& ... args)
    {
        return std::shared_ptr<Foo>( new Foo(std::forward<T>(args)... ));
    }

    int getVal() { return val; }
private:
    int val = 0;
};

int main()
{
    auto ptr2 = Foo::create(3);

    auto ptr3 = ptr2->shared_from_this();
    std::cout << "Value is: " << ptr3->getVal() << " use count is: " << ptr3.use_count() << std::endl;
    return 0;
}
