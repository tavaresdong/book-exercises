#include <iostream>

using namespace std;

class Employee {
public:
    Employee(string str) : name(str), id(curMaxId++) { }
    Employee(const Employee& emp);
    Employee& operator=(const Employee& emp);
    friend ostream& operator<<(ostream& os, const Employee& emp);
private:
    string name;
    int id;
    static int curMaxId;
};

ostream& operator<< (ostream& os, const Employee& emp) {
    os << emp.name << " : " << emp.id;
    return os;
}

int Employee::curMaxId = 0;

Employee::Employee(const Employee& emp) : name(emp.name), id(curMaxId++) {
    
}

Employee& Employee::operator= (const Employee& emp)
{
     name = emp.name;
     id = curMaxId++;
}

int main(int argc, char **argv) {
    Employee emp("Eric Chen");
    Employee emp2 = emp;
    Employee emp3("Dirk Nowitzki");
    cout << emp << emp2;
    emp = emp3;
    cout << emp << endl;
    return 0;
}
