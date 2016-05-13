#include <iostream>
#include <algorithm>

using namespace std;

// 10.14
// a lambda that takes two integers and return their sum
auto mysum = [] (int val1, int val2) { return val1 + val2; };

string make_plural(int cnt, string wd, string app) {
    if (cnt == 1) {
        return wd;
    } else {
        return wd + app;
    }
}

// 10.16
void biggies(vector<string> &words,
             vector<string>::size_type sz) {
    sort(words.begin(), words.end());
    auto uniiter = unique(words.begin(), words.end());
    words.erase(uniiter, words.end());

    stable_sort(words.begin(), words.end(),
                    [] (const string& str1, const string& str2)
                    { return str1.size() < str2.size();});

    auto bigger = find_if(words.begin(), words.end(), 
                    [sz] (const string& str) { return str.size() >= sz; });

    auto count = words.end() - bigger;
    cout << count << make_plural(count, "word", "s") << "of length " << sz
         << " or longer" << endl;
    for_each(bigger, words.end(), [] (const string& str) { cout << str << endl;});
}

int main(int argc, char **argv) {
    cout << mysum(2, 4) << endl;
    // 10.15
    // a lambda that captures the integers from its surrouding scope
    // and another integer from parameter and return the sum 
    int outer = 3;
    auto capsum = [&outer](int par) { return outer + par; };
    cout << capsum(3) << endl;
    
    vector<string> vec{"what", "a", "stupid", "day", "my", "day", "is", "totally", "ruined"};
    biggies(vec, 4);
}
