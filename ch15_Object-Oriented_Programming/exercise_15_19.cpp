/*
 * 假设543页和544页的每个类都有如下形式的成员函数：
 * void memfcn(Base &b) { b = *this; }
 * 对于每个类，分别判断上面的函数是否合法。
 */

/*
 * Base: 合法
 * Sneaky: 合法，但只会拷贝其基类部分
 * Pal: 非法，不存在类型转换规则
 * Pub_Derv: 合法
 * Priv_Derv: 合法
 * Derived_from_Public: 合法
 * Derived_from_Private: 非法，Base::Base is inaccessible
 */

class Pal;

class Base {
    friend class Pal;
    void memfcn(Base &b) { b = *this; }
};
class Sneaky : public Base {
    void memfcn(Base &b) { b = *this; }
};
class Pal {
    // void memfcn(Base &b) { b = *this; }
};
class Pub_Derv : public Base {
    void memfcn(Base &b) { b = *this; }
};
class Priv_Derv : private Base {
    void memfcn(Base &b) { b = *this; }
};
class Derived_from_Public : public Pub_Derv {
    void memfcn(Base &b) { b = *this; }
};
class Derived_from_Private : public Priv_Derv {
    // void memfcn(Base &b) { b = *this; }
};


int main(int argc, char const *argv[]) {
    return 0;
}
