#ifndef _PERSON_H_
#define _PERSON_H_
#include <iostream>

class Person {
    friend std::istream& direct_read(std::istream& os, Person &person);
private:
    std::string name;
    std::string address;

public:
    Person() = default;
    explicit Person(std::string n, std::string a = "China") : name(n), address(a) {}
    Person(std::string n, std::string a) : name(n), address(a) {}

    const std::string& getAddress() const {return address;}
    const std::string& getName() const  {return name;}

    void setAddress(std::string add)
    {
        address = add;
    }

    void setName(std::string na)
    {
        name = na;
    }
};

// Friend function can access private data of the class
std::istream& direct_read(std::istream& is, Person& person)
{
    is >> person.name >> person.address;
    return is;
}

// Functions related to a class should be
// put in the same header file with that class
std::ostream& print(std::ostream& os, const Person &person)
{
    os << person.getName() << " : " << person.getAddress();
    return os;
}

std::istream& read(std::istream& is, Person& person)
{
    std::string na, add;
    is >> na >> add;
    person.setAddress(add);
    person.setName(na);
    return is;
}

#endif
