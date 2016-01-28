#ifndef _WINDOW_MGR_H_
#define _WINDOW_MGR_H_
#include <vector>
#include "Screen.h"

class Window_mgr {
private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};

};

#endif
