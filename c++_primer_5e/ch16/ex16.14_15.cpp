#include <iostream>

using namespace std;

template <unsigned H, unsigned W>
class Screen {
public:
    Screen() : height(H), width(W) {};
    friend ostream& operator << (ostream& out, const Screen<H, W>& s)
    {
        unsigned i, j;
        for (i = 0; i < s.height; i++) {
            out << s.width << endl;
        }
        return out;
    } 

private:
    int height;
    int width;
};

int main(int argc, char** argv)
{
    Screen<2, 3> s;
    cout << s << endl;
}
