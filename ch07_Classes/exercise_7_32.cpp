/*
 * 定义你自己的Screen和Window_mgr，其中clear是Window_mgr的成员，是Screen的友元。
 */

#include <iostream>
#include <string>
#include <vector>

class Screen;
class Window_mgr {
public:
    using ScreanIndex = std::vector<Screen>::size_type;
    void clear(ScreanIndex);
    Window_mgr();

private:
    std::vector<Screen> screens;
};


class Screen {
public:
    //typedef std::string::size_type pos;
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(height * width, ' ') {}
    Screen(pos ht, pos wd, const char c) : height(ht), width(wd), contents(height * width, c) {}
    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen move(pos r, pos c);
    void some_member() const;

    //api
    Screen set(char);
    Screen set(pos, pos, char);

    Screen display(std::ostream &os) {
        do_display(os);
        return *this;
    }
    const Screen display(std::ostream &os) const {
        do_display(os);
        return *this;
    }
    friend void Window_mgr::clear(ScreanIndex i);

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    mutable size_t access_ctr;

    void do_display(std::ostream &os) const { os << contents; }
};

inline char Screen::get(pos ht, pos wd) const {
    pos row = ht * wd;
    return contents[row];
}

Screen Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

void Screen::some_member() const {
    ++access_ctr;
}

inline Screen Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}
inline Screen Screen::set(pos r, pos col, char c) {
    contents[r * width + col] = c;
    return *this;
}

Window_mgr::Window_mgr() {
    screens = {Screen(24, 80, ' ')};
}

void Window_mgr::clear(ScreanIndex i) {
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

int main(void) {
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";
}
