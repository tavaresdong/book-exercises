#include "Quote.h"
#include <iostream>

int main(int argc, char **argv)
{
    Quote q("good", 2);
    Bulk_quote b("good", 2,  10, 0.1);

    print_total(std::cout, q, 12);
    print_total(std::cout, b, 12);

    return 0;
}
