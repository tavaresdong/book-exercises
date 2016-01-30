#ifndef _DEBUG_DELETE_H_
#define _DEBUG_DELETE_H_
#include <iostream>

class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) {}

    template <typename T>
    void operator() (T* pt) 
    {
        os << "Deleting pointer pt." << std::endl;
        delete pt;
    }

private:
    std::ostream& os;
};



#endif

