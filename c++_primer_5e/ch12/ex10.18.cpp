#include <iostream>
#include <algorithm>

using namespace std;

string make_plural(int cnt, string word, string app) {
    if (cnt == 1) {
        return word;
    } else {
        return word + app;
    }
}
// ex10.18
void biggies(vector<string> &words,
             vector<string>::size_type sz) {
    sort(words.begin(), words.end());
    auto uniiter = unique(words.begin(), words.end());
    words.erase(uniiter, words.end());

    //auto bigger = find_if(words.begin(), words.end(), 
    //                [sz] (const string& str) { return str.size() >= sz; });
    auto bigger = stable_partition(words.begin(), words.end(),
                    [sz] (const string& str) { return str.size() >= sz; });

    auto count = bigger - words.begin();
    cout << count << make_plural(count, "word", "s") << "of length " << sz
         << " or longer" << endl;

    stable_sort(words.begin(), bigger,
                    [] (const string& str1, const string& str2)
                    { return str1.size() < str2.size(); });
    for_each(words.begin(), bigger, [] (const string& str) { cout << str << endl;});
}

int main(int argc, char **argv) {
    vector<string> vec{"what", "a", "stupid", "day", "my", "day", "is", "totally", "ruined"};
    biggies(vec, 4);
}
