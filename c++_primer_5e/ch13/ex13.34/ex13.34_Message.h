#ifndef _EX_MESSAGE_H_
#define _EX_MESSAGE_H_
#include <set>
#include <string>

class Folder;

class Message {
    friend class Folder;
    friend void swap(Message& m1, Message &m2);
public:
    Message(const std::string &str = "") :
        contents(str) { };

    // Copy Control
    Message(const Message&);
    Message& operator=(const Message&);
    Message(Message &&);
    Message& operator=(Message &&);
    ~Message();

    // add/remove this message from the specified folder's set of messages
    void save(Folder&);
    void remove(Folder&);

    void addFolder(Folder*);
    void remFolder(Folder*);
private:
    std::string contents;
    std::set<Folder*> folders;
    // add this message to the folders that point to the parameter
    void add_to_Folders(const Message&);
    void remove_from_Folders();
    void move_Folders(Message *m);
};

class Folder {
public:
    void addMsg(Message* msg);
    void remMsg(Message* msg);
private:
    std::set<Message*> messages;
};
#endif
