#include <iostream>
#include <memory>

using namespace std;

class Connection {
public:
    Connection() : val(new int(20)) {}
    void free() { delete val; }
private:
    int *val;
};


void end_connection(Connection *p) {
    p->free();
    cout << "Ending the connection" << endl;
}

int main(int argc, char** argv) {
    Connection c1, c2;
    shared_ptr<Connection>(&c1, end_connection);
    shared_ptr<Connection>(&c2, [](Connection* p)
            { p->free(); cout << "Lambda end connection" << endl; });
    return 0;
}
