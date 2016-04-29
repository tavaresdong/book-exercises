#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char **argv) {
    const char* str1 = "Hello ";
    const char* str2 = "World";
    char *str = new char[12];
    strncpy(str, str1, 6);
    strncpy(str + 6, str2, 6);   
    cout << str << endl;

    string str3("Good");
    string str4("job");
    cout << str3 + str4 << endl;
    return 0;
}
