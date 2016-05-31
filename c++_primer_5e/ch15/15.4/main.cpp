#include "Quote.h"
#include <iostream>

int main(int argc, char **argv)
{
    Quote q("good", 2);
    Bulk_quote b("good", 2,  10, 0.1);
    Limit_quote l("good", 2, 10, 0.1, 15);

    print_total(std::cout, q, 20);
    print_total(std::cout, b, 20);
    print_total(std::cout, l, 20);

    return 0;
}
