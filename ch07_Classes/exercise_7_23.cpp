/*
 * 编写你自己的Screen类。
 */

#include <iostream>
#include <string>

class Screen {
public:
    //typedef std::string::size_type pos;
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(height * width, c) {}
    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    void some_member() const;

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    mutable size_t access_ctr;
};

inline char Screen::get(pos ht, pos wd) const {
    pos row = ht * wd;
    return contents[row];
}

Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

void Screen::some_member() const {
    ++access_ctr;
}

int main(void) {
    Screen screen(24, 80, 'A');
    std::cout << screen.get() << std::endl;
    return 0;
}
