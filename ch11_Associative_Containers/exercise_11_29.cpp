/*
 * 如果给定的关键字不在容器中，upper_bound, lower_bound和equal_range分别会返回什么？
 */

/*
 * 如果关键字在容器中，
 * lower_bound 返回的迭代器将指向第一个具有给定关键字的元素，
 * upper_bound 返回的的迭代器指向最后一个匹配给定关键字的元素之后的位置。
 * equal_range 返回一个迭代器pair，
 * 第一个迭代器指向第一个与关键字匹配的元素，第二个迭代器指向最后一个匹配元素之后的位置。
 *
 * 如果关键字不在容器中，
 * lower_bound upper_bound 返回的迭代器指向一个不影响排序的关键字插入位置，
 * equal_range 返回一个迭代器pair，两个迭代器均指向关键字可插入的位置。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
