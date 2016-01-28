#ifndef _SCREEN_H_
#define _SCREEN_H_
#include <iostream>             // For ostream

class Screen {
public:
    typedef std::string::size_type pos;

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

public:
    Screen() = default;
    Screen(pos ht, pos wd, char c = ' ') : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[cursor]; }
    char get(pos ht, pos wd) const;
    Screen& set(char);
    Screen& set(pos, pos, char);

    Screen& move(pos r, pos c);
    Screen& display(std::ostream& os) { do_display(os); return *this; }
    const Screen& display(std::ostream& os) const { do_display(os); return *this; }

private:
    void do_display(std::ostream& os) const { os << contents; }

};

inline Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen& Screen::set(pos r, pos c, char rep)
{
    contents[r * width + c] = rep;
    return *this;
}

inline char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

Screen& Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}



#endif
