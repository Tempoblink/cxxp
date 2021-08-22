#include "Folder.h"
#include "Messsage.h"

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
