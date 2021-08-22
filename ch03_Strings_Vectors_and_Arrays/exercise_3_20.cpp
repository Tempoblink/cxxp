/*
 * 读入一组整数并把它们存入一个vector对象，将每对相邻整数的和输出出来。
 * 改写你的程序，这次要求先输出第1个和最后1个元素的和，接着输出第2个和倒数第2个元素的和，以此类推。
 */

#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> ievc;
    int num;
    std::cout << "Enter some numbers: ";
    while (std::cin >> num) {
        ievc.push_back(num);
    }

    //相邻
    for (decltype(ievc.size()) i = 1; i < ievc.size(); ++i) {
        std::cout << ievc[i - 1] + ievc[i] << " ";
    }
    std::cout << std::endl;

    //前后
    for (decltype(ievc.size()) i = 0, j = ievc.size() - 1; i < j; ++i, --j) {
      std::cout << ievc[i] + ievc[j] << " ";
    }
    std::cout << std::endl;
}
