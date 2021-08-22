/*
 * 在buildMap中，如果进行如下改写，会有什么效果？
 *
 * trans_map[key] = value.substr(1);
 * 改为trans_map.insert({key, value.substr(1)})
 */

/*
 * 下标版本的，不管容器中是否存在key，都会插入，若存在则会更新其键值。
 * 插入版本的，如果后续插入相同键值的元素，则不会改变原有的元素。
 */

int main(int argc, char const *argv[]) {
    return 0;
}
