#include <iostream>
#include "Screen.h"
#include "Window_mgr.h"

// Forward declaration
class Y;

class X {
    Y* pointery;

};

class Y {
    X x;
};

int main(int argc, char **argv)
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";

    Window_mgr win;
    win.clear(0);

    return 0;
}
