/*
 * 设计并实现对应的Folder类。
 * 此类应该保存一个指向Folder中包含的Message的set。
 */
#include "include/Messsage.h"
#include <iostream>
#include <memory>
#include <set>
#include <string>

class Folder {
    friend class Message;
    friend std::ostream &print(std::ostream &, const Folder &);

public:
    Folder(const std::string &name) : Folder_name(name), messages(std::make_shared<std::set<Message *>>()) {}
    Folder(const Folder &) = delete;
    Folder &operator=(const Folder &) = delete;
    ~Folder();

    std::string get_folder_name() const { return Folder_name; }

private:
    std::string Folder_name;
    std::shared_ptr<std::set<Message *>> messages;
    void addMsg(Message *);
    void remMsg(Message *);
};

Folder::~Folder() {
    for (auto m : *messages)
        m->remove(*this);
}
void Folder::addMsg(Message *s) {
    messages->insert(s);
}
void Folder::remMsg(Message *s) {
    messages->erase(s);
}
std::ostream &print(std::ostream &os, const Folder &f) {
    os << "Folder name: " << f.Folder_name << std::endl;
    os << "Message: ";
    for (auto m : *f.messages) {
        os << m->get_message() << " ";
    }
    os << std::endl;
    return os;
}


int main(int argc, char const *argv[]) {
    Message m1("Hello,world.");
    Folder f1("new messages");
    m1.save(f1);
    print(std::cout, f1);
    return 0;
}
