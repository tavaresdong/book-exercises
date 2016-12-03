#include <memory>
#include <iostream>

class Foo : public std::enable_shared_from_this<Foo>
{
public:
    std::shared_ptr<Foo> getFoo()
    {
        return shared_from_this();
    }
};

// Bad way of creating shared_ptr from this pointer
class Bar
{
public:
    std::shared_ptr<Bar> getBar()
    {
        return std::shared_ptr<Bar>(this);
    }

    ~Bar()
    {
        std::cout << "Destructing Bar" << std::endl;
    }
};

int main(int argc, char **argv)
{
    // 1. bad way, different control blocks
    // Will lead to double free corruption
    /*
    std::shared_ptr<Bar> bad1 = std::make_shared<Bar>();
    std::shared_ptr<Bar> bad2 = bad1->getBar();
    std::cout << "bad2's use count is: " << bad2.use_count() << std::endl;
    */

    // 2. bad way, this pointer not already in control block:
    Foo* foo = new Foo();
    try {
        auto spf = foo->getFoo();
    }
    catch (std::bad_weak_ptr& bwp)
    {
        // Until c++17, this is undefined behaviour
        std::cout << bwp.what() << std::endl;
    }

    // 3. Correct way
    // the shared_ptr constructor will detect enable_shared_from_this
    // and init a weak_ptr inside it to point to current pointer's control block
    // and subsequent call to shared_from_this will directly use that control block
    std::shared_ptr<Foo> spf = std::make_shared<Foo>();
    auto spf2 = spf->getFoo();
    std::cout << "spf's use count is: " << spf2.use_count() << std::endl;
}
