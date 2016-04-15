#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print_vector(const vector<T>& vec)
{
    for (auto iter = vec.begin(); iter != vec.end(); ++iter)
        cout << *iter << endl;
}

void multiple_vector()
{
    vector<int> vec(10, 20);
    for (auto iter = vec.begin(); iter != vec.end(); ++iter)
        *iter = 2 * *iter;

    for (int v : vec)
        cout << v << endl;
}

// Ex 3.25
vector<unsigned> split_scores() 
{
    vector<unsigned> scores(11, 0); 
    int grade;
    auto begin_iter = scores.begin();
    while (cin >> grade) {
        ++*(begin_iter + grade / 10);
    }

    return scores;
}

int main(int argc, char **argv)
{
    multiple_vector();

    vector<unsigned> scores = split_scores();
    print_vector(scores);
    return 0;
}
