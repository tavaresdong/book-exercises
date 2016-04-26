
// auto p = new int();
// auto sp = make_shared<int>();
//
// process(sp); // ok
// process(new int()); // Error, need explicit construction
// process(p); // Error, same as before
// process(shared_ptr<int>(p)); // Ok, Process on , but memory is deleted when return
