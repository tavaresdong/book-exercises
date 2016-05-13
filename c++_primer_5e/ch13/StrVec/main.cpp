#include "StrVec.h"
#include "String.h"
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    StrVec v;
    v.push_back("good");
    std::cout << v.size() << std::endl;

    std::cout << "Test String" << std::endl;
    // String str;
    // String str2("porn");
    // std::cout << str.size() << " " << str << std::endl;
    // std::cout << str2.size() << " " << str2 << std::endl;

    std::vector<String> vec;
    String str("job"), str2("hi");
    // this will call copy constructor twice
    vec.push_back(String("good"));
    vec.push_back(str);

    str = str2;
    return 0;
}