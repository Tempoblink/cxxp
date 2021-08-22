#include "Messsage.h"
#include "Folder.h"

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
