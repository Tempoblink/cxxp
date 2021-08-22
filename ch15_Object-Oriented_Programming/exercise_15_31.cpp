/*
 * 已知s1、s2、s3和s4都是string，判断下面的表达式分别创建了什么样的对象：
 *
 * (a) Query(s1) | Query(s2) & ~Query(s3);
 * (b) Query(s1) | (Query(s2) & ~Query(s3));
 * (c) (Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));
 */

/*
 * (a) s1 或 s2存在的 且s3不存在的行
 * (b) s1 存在 或 ( s2存在且s3不存在的行)
 * (c) (s1存在并且s2存在) 或 (s3并且s4存在)
 */

int main(int argc, char const *argv[]) {
    return 0;
}
