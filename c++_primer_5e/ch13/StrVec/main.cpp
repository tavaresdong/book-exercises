#include "StrVec.h"
#include <iostream>

int main(int argc, char **argv)
{
    StrVec v;
    v.push_back("good");
    std::cout << v.size() << std::endl;
    return 0;
}