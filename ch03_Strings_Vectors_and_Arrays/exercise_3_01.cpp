/*
 * 使用恰当的using声明重做1.4.1节和2.6.2节的练习。
 */

#include <iostream>

using std::cin, std::cout, std::endl;


int main(void) {
    //1.4.1 exercise_1_09
    int sum = 0, val = 50;
    while (val <= 100) {
        sum += val;
        ++val;
    }
    cout << "The sum is: " << sum << endl;

    //1.4.1 exercise_1_10
    val = 10;
    while (val >= 0) {
      cout << val << " ";
      --val;
    }
    cout << endl;

    //1.4.1 exercise_1_11
    cout << "Enter two numbers: ";
    cin >> val >> sum;
    if (sum < val) {
      int tmp = sum;
      sum = val;
      val = tmp;
    }
    while (val <= sum) {
      cout << val <<" ";
      ++val;
    }
    cout << endl;

    //2.6.2 省略
    return 0;
}
