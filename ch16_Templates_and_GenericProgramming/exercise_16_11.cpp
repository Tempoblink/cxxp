/*
 * 下面List的定义是错误的。应如何修正它？
 *
 * template<typename elemType> class ListItem;
 * template<typename elemType> class List {
 * public:
 *      List<elemType>();
 *      List<elemType>(const List<elemType> &);
 *      List<elemType>& operator=(const List<elemType> &);
 *      ~List();
 *      void insert(ListItem *ptr, elemType value);
 * private:
 *      ListItem *front, *end;
 * }
 */

#include <cstddef>
#include <list>
template<typename elemType>
class ListItem;

template<typename elemType>
class List {
public:
    List<elemType>() = default;
    List<elemType>(const List<elemType> &);
    List<elemType> &operator=(const List<elemType> &);
    ~List();
    void insert(ListItem<elemType> *ptr, elemType value);

private:
    ListItem<elemType> *front, *end;
};

int main(int argc, char const* argv[])
{
  return 0;
}
