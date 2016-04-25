// 12.7
// bool b() {
//     int* p = new int;
//     return p;
// }
//
// What's wrong?
// p is converted to bool and return
// so caller cannot delete on this pointer
// and we cannot cast back bool->int*, because there information is lost
// the allocated memory is leaked!
//
bool b() {
    int *p = new int;
    return p;
}

int main(int argc, char **argv) {
    auto val = b();
    int *p = (int*) val;
    delete p;
    return 0;
}
