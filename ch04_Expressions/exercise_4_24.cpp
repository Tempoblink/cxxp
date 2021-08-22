/*
 * 本节的示例程序将成绩划分成high pass、pass和fail三种，它的依据是条件运算符满足右结合律。假如条件运算符满足的是左结合律，求值过程将是怎样的？
 */

/*
 * finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
 *
 * 会把这个表达式结合在一起(grade > 90) ? "high pass" : (grade < 60)，然后再拿结果和后面的表达式组成条件表达式。如同：
 *
 * finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass"; 
 *
 * 因此，如果grade > 90，那么finalgrade恒为fail。
 */

int main(void) {
    return 0;
}
