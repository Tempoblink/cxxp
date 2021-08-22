/*
 * 关于下面的代码，请指出每一个变量的类型以及程序结束时它们各自的值。
 *
 * int a = 3, b = 4;
 * decltype(a) c = a;
 * decltype((b)) d = a;
 * ++c;
 * ++d;
 */

/*
 * a->int    b->int
 * c->int    d->int&
 * a = 4, b = 4, c = 4, d = 4
 */

#include <iostream>

int main(void)
{
  int a = 3, b= 4;
  decltype(a) c = a;
  decltype((b)) d = a;
  ++c;
  ++d;

  std::cout << "a = " << a << " at " << reinterpret_cast<int_fast64_t>(&a) << std::endl;
  std::cout << "b = " << b << " at " << reinterpret_cast<int_fast64_t>(&b) << std::endl;
  std::cout << "c = " << c << " at " << reinterpret_cast<int_fast64_t>(&c) << std::endl;
  std::cout << "d = " << d << " at " << reinterpret_cast<int_fast64_t>(&d) << std::endl;

  return 0;
}
