/*
 * 编写Screen类模板，用非类型参数定义Screen的高和宽。
 */

#include <iostream>
#include <ostream>
#include <string>

template<unsigned height, unsigned width>
class Screen;

template<unsigned height, unsigned width>
std::istream &operator>>(std::istream &, Screen<height, width> &);

template<unsigned height, unsigned width>
class Screen {
    friend std::istream &operator>><height, width>(std::istream &, Screen<height, width> &);

public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(char c) : contents(height * width, c) {}
    char get() const { return contents[cursor]; }
    inline char get(pos t, pos wd) const;
    Screen &move(pos r, pos c);

    Screen &set(char c);
    Screen &set(pos row, pos col, char c);
    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }
    const Screen display(std::ostream &os) const {
        do_display(os);
        return *this;
    }

private:
    void do_display(std::ostream &os) const { os << contents; }
    pos cursor = 0;
    std::string contents;
};

template<unsigned height, unsigned width>
inline char Screen<height, width>::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

template<unsigned height, unsigned width>
Screen<height, width> &Screen<height, width>::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

template<unsigned height, unsigned width>
Screen<height, width> &Screen<height, width>::set(char c) {
    contents[cursor] = c;
    return *this;
}

template<unsigned height, unsigned width>
Screen<height, width> &Screen<height, width>::set(pos row, pos col, char c) {
    contents[row * width + col] = c;
    return *this;
}

template<unsigned height, unsigned width>
std::istream &operator>>(std::istream &is, Screen<height, width> &s) {
    std::string line;
    if (std::getline(is, line)) {
        for (auto c : line) {
            s.set(c);
            s.cursor = (s.cursor + 1) % s.contents.size();
        }
    }
    return is;
}

template<unsigned height, unsigned width>
std::ostream &operator<<(std::ostream &os, const Screen<height, width> &s) {
    for (size_t l = 0; l < height; ++l) {
        for (size_t w = 0; w < width; ++w)
            os << s.get(l, w);
        os << std::endl;
    }
    return os;
}

int main(void) {
    Screen<24, 80> s('A');
    std::cout << s << std::endl;
    return 0;
}
