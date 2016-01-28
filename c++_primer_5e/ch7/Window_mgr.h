#ifndef _WINDOW_MGR_H_
#define _WINDOW_MGR_H_
#include <vector>
#include "Screen.h"

class Window_mgr {
private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};

public:
    using ScreenIndex = std::vector<Screen>::size_type;

    void clear(ScreenIndex);
};

void Window_mgr::clear(ScreenIndex i)
{
    Screen& s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

#endif
