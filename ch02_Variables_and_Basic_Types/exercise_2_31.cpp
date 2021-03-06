/*
 * 假设已有上一个练习中所做的那些声明，则下面的哪些语句是合法的？请说明顶层const和底层const在每个例子中有何体现。
 * 
 * r1 = v2;
 * p1 = p2; p2 = p1;
 * p1 = p3; p2 = p3;
 */

/*
 * r1 = v2; 是合法的，v2是顶层const，可以赋值给别的变量。
 * p1 = p2; 是不合法的，因为p2是底层const，不能赋值给普通指针。
 * p2 = p1; 是合法的，p2没有顶层const属性，可以被修改。
 * p1 = p3; 是不合法的，因为p3拥有底层const属性，不能赋值给普通指针。
 * p2 = p3; 是合法的，p2没有顶层const属性，可以被修改。
 */

int main(void) {
    return 0;
}
