#include "ex13.34_Message.h"
#include <utility>
#include <iostream>

Message::Message(const Message& rhs):
    contents(rhs.contents), folders(rhs.folders)
{
    add_to_Folders(rhs);
}

Message& Message::operator=(const Message& m)
{
    // Prevent against self-assignment
    remove_from_Folders();
    contents = m.contents;
    folders = m.folders;
    add_to_Folders(m);
    return *this;
}

Message::~Message()
{
    remove_from_Folders();
}

void swap(Message& m1, Message &m2)
{
    using std::swap;
    m1.remove_from_Folders();
    m2.remove_from_Folders();
    swap(m1.contents, m2.contents);
    swap(m1.folders, m2.folders);
    for (auto f : m1.folders)
    {
        f->addMsg(&m1);
    }
    for (auto f : m2.folders)
    {
        f->addMsg(&m2);
    }
}

// add/remove this message from the specified folder's set of messages
void Message::save(Folder& f)
{
    std::cout << "Message saved to folder" << std::endl;
    folders.insert(&f);
    f.addMsg(this);
}
    
void Message::remove(Folder& f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::addFolder(Folder* f)
{
    folders.insert(f);
}

void Message::remFolder(Folder* f)
{
    folders.erase(f);
}


void Message::add_to_Folders(const Message& msg)
{
    for (auto f : msg.folders)
    {
        f->addMsg(this);
    }
}

void Message::remove_from_Folders()
{
    for (auto f : folders) 
    {
        f->remMsg(this);
    }
}

void Folder::addMsg(Message* msg)
{
    std::cout << "Message inserted to folder" << std::endl;
    messages.insert(msg);
}

void Folder::remMsg(Message* msg)
{
    messages.erase(msg);
}
