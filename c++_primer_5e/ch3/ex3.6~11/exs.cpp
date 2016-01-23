#include <iostream>
#include <cctype>           // for ispunct

using namespace std;

void substitute_with(string& str, char to_replace)
{
    for (decltype(str.size()) index = 0;
                    index < str.size(); index++)
        str[index] = to_replace;

}

void auto_substitute_with(string& str, char to_replace)
{
    // Mention the & operator
    for (auto& c : str)
        c = to_replace;
}

void print_without_punct(const string& str)
{
    for (auto c : str)
        if (!ispunct(c))
            cout << c;
    cout << endl;
}

int main(int argc, char **argv)
{
    string str1("What a Good Day!"), str2 = "How you doing?";
    string str3("Hi, boys! My question is how old are you?");
    substitute_with(str1, 'X');
    auto_substitute_with(str2, 'O');
    cout << str1 << " " << str2 << endl;
    print_without_punct(str3);

    return 0;
}
