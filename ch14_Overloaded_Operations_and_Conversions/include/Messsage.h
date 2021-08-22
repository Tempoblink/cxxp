#pragma once

#include <ostream>
#include <set>
#include <string>

class Folder;

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
    std::string get_message() const { return contents; }

private:
    std::string contents;
    std::set<Folder *> folders;
    void add_to_Folders(const Message &);
    void remove_from_Folders();
};
