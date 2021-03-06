/*
 * 解释下面的循环，它来自13.5节（第469页）中的StrVec::reallocate:
 *
 * for (size_t i = 0; i != size(); ++i)
 *        alloc.construct(dest++, std::move(*elem++));
 */

/*
 * 先将eleme往后递增，返回原来的elem所指对象(一个左值)，通过move得到其右值引用，
 * 然后调用construct的右值引用版本，从而窃取其中的资源，避免了资源的拷贝。
 */


#include <climits>
#include <iostream>

int main(int argc, char const* argv[])
{
  // 左值转为右值的截断
  double i = 4.5;
  std::cout << i << std::endl;
  auto j = static_cast<int &&>(i); 
  std::cout << j << std::endl;
  return 0;
}
