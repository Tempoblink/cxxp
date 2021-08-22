/*
 * 为Message类添加成员，实现向folders添加或删除一个给定的Folder*。
 * 这两个成员类似Folder类的addMsg和remMsg操作。
 */

#include "include/Folder.h"
#include <iostream>
#include <ostream>
#include <set>
#include <string>

class Message {
    friend class Folder;
    friend std::ostream &print(std::ostream &, const Message &);

public:
    explicit Message(const std::string &str = "") : contents(str) {}
    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();

    void save(Folder &);
    void remove(Folder &);

    void save_ptr(Folder *);
    void remove_ptr(Folder *);
    std::string get_message() const { return contents; }

private:
    std::string contents;
    std::set<Folder *> folders;
    void add_to_Folders(const Message &);
    void remove_from_Folders();
};

Message::Message(const Message &s) : contents(s.contents), folders(s.folders) {
    add_to_Folders(s);
}
Message &Message::operator=(const Message &s) {
    remove_from_Folders();
    contents = s.contents;
    folders = s.folders;
    add_to_Folders(s);
    return *this;
}
Message::~Message() {
    remove_from_Folders();
}
void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}
void Message::remove(Folder &f) {
    folders.erase(&f);
    f.addMsg(this);
}
void Message::add_to_Folders(const Message &s) {
    for (auto folder : s.folders)
        folder->addMsg(this);
}
void Message::remove_from_Folders() {
    for (auto folder : folders)
        folder->remMsg(this);
}
std::ostream &print(std::ostream &os, const Message &s) {
    os << "Message: " << s.contents << std::endl;
    os << "Folder_name: ";
    for (auto m : s.folders) {
        os << m->get_folder_name() << " ";
    }
    os << std::endl;
    return os;
}
void Message::save_ptr(Folder *f) {
    folders.insert(f);
    f->addMsg(this);
}
void Message::remove_ptr(Folder *f) {
    folders.erase(f);
    f->remMsg(this);
}


int main(int argc, char const *argv[]) {
    Folder f1("new messages");
    Message m1("Hello");
    m1.save_ptr(&f1);

    print(std::cout, m1);
    print(std::cout, f1);
    return 0;
}
