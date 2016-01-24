#include <iostream>
#include <initializer_list>

using namespace std;

// Ex 6.10
void swap(int *pa, int *pb)
{
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

// Ex 6.12
void swap_ref(int& a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// Ex 6.27
int sum_initlist(initializer_list<int> list)
{
    int sum = 0;
    for (auto val : list)
        sum += val;
    return sum;
}

int main(int argc, char **argv)
{
    int a = 1, b = 2;
    swap(&a, &b);
    cout << a << " " << b << endl;
    swap_ref(a, b);
    cout << a << " " << b << endl;

    if (argc != 3) {
        cout << "Should have 3 parameters" << endl;
    } else {
        string arg1(argv[1]), arg2(argv[2]);
        arg1 += arg2;
        cout << arg1 << endl;
    }

    cout << sum_initlist({2, 3, 4, 5});

    return 0;
}
