#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

bool check_size(const string& str, string::size_type sz) {
    return str.size() >= sz;
}


// Bind takes (1 + param count of the callable) parameters

int main(int argc, char** argv) {
    vector<string> vec{"good", "bad", "sad", "happy"};
    cout << count_if(vec.begin(), vec.end(),
                     bind(check_size, _1, 4)) << endl;

    string str("haha");
    vector<int> v{1, 2, 3, 4, 5};
    auto iter = find_if_not(v.begin(), v.end(),
                        bind(check_size, ref(str), _1));
    cout << iter - v.begin() << endl;
    return 0;
}
