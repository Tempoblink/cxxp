/*
 * 指出下面代码中的索引错误。
 *
 * constexpr size_t array_size = 10;
 * int ia[array_size];
 * for (size_t ix = 1; ix <= array_size; ++ix ) {
 *     ia[ix] = ix;
 * }
 */

/*
 * 超出数组最大边界。ix不能等于array_size。
 */
