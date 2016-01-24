#include <iostream>
#include <cstring>

using namespace std;

void copy_str()
{
    char str1[10] = "abcdefghi";
    char str2[2]  = "j";
    char str3[11];

    strcpy(str3, str1);

    strcat(str3 + 9, str2);

    cout << str3 << endl;
}

int main(int argc, char **argv)
{
    copy_str();
    return 0;
}
