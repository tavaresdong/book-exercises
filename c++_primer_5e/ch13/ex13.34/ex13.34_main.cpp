#include "ex13.34_Message.h"

using namespace std;

int main(int argc, char **argv) {
    Message m("good");
    Folder f;
    m.save(f);
    return 0;
}
