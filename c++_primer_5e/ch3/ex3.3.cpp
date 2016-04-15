#include <iostream>
#include <vector>

using namespace std;


// Ex 3.14
vector<int> read_int_vector()
{
    int val;
    vector<int> vec;
    cin.clear();
    while (cin >> val) 
        vec.push_back(val);
    
    return vec;
}   


// Ex 3.15
vector<string> read_string_vector()
{
    string str;
    vector<string> vec;
    cin.clear();
    while (cin >> str)
        vec.push_back(str);

    return vec;
}

// Ex 3.17
void read_vector_and_make_upper()
{
    vector<string> vec;
    string str;
    cin.clear();
    while (cin >> str)
        vec.push_back(str);
    for (auto &s : vec)
        for (auto &c : s)
            c = toupper(c);
    for (const auto &s : vec)
        cout << s << endl;
}

// Ex 3.20
void sum_vector()
{
    vector<int> vec;
    int val;
    cin.clear();
    while (cin >> val)
        vec.push_back(val);
    for (decltype(vec.size()) start = 0, end = vec.size() - 1;
                    start <= end; ++start, --end) {
        cout << vec[start] + vec[end] << endl;
    }
}


// Ex 3.16
template <typename T>
void print_vector(const vector<T>& vec)
{
    cout << "size is " << vec.size() << endl;
    for (auto &t : vec)
        cout << t << endl;
}


int main(int argc, char **argv)
{
    auto v1 = read_int_vector();
    print_vector(v1);

    auto v2 = read_string_vector();
    print_vector(v2);

    read_vector_and_make_upper();

    sum_vector();

    return 0;
}

