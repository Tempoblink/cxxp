#pragma once

#include <memory>
#include <ostream>
#include <set>
#include <string>

class Message;

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
