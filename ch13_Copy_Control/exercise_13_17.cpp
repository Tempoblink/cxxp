/*
 * 分别编写前三题所描述的numbered和f， 验证你是否正确预测了输出结果。
 */

#include <cstdlib>
#include <ctime>
#include <iostream>

class numered;
void f1(numered s);
void f2(numered &s);

class numered {
    friend void f1(numered s);
    friend void f2(numered &s);

public:
    numered();
    numered(const numered &);
    numered &operator=(const numered &);
    ~numered() {}

    int call() const { return mysn; }

private:
    int mysn;
};

numered::numered() {
    std::srand(time(0));
    mysn = rand();
}

numered::numered(const numered &n) {
    //1
    // mysn = n.mysn;

    //2
    mysn = rand();
}

numered &numered::operator=(const numered &rhs) {
    //1
    mysn = rhs.mysn;

    //2
    mysn = rand();
    return *this;
}

void f1(numered s) { std::cout << s.mysn << std::endl; }

void f2(numered &s) { std::cout << s.mysn << std::endl; }

int main(int argc, char const *argv[]) {
    numered a, b = a, c = b;
    std::cout << "-----main()-----" << std::endl;
    std::cout << a.call() << std::endl;
    std::cout << b.call() << std::endl;
    std::cout << c.call() << std::endl;

    std::cout << "------f1()------" << std::endl;
    f1(a);
    f1(b);
    f1(c);

    std::cout << "------f2()------" << std::endl;
    f2(a);
    f2(b);
    f2(c);

    return 0;
}
