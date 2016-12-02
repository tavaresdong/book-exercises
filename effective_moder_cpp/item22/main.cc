#include "widget.h"

int main(int argc, char **argv)
{
    Widget w;
    Widget r;
    r = std::move(w);
    w = r;
}
