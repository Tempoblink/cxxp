/*
 * 使用你自己的Sales_data类重写1.5.1节（第20页）、1.5.2节（第21页）和1.6节（第22页）的练习。
 * 眼下先把Sales_data类的定义和main函数放在同一个文件里。
 */

#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};


int main(void) {
    //1.5.1
    /*
    std::cout << "1.5.1" << std::endl;
    Sales_data item1, item2;
    double price = 0.0;
    std::cin >> item1.bookNo >> item1.units_sold >> price;
    item1.revenue = item1.units_sold * price;
    price = 0.0;
    std::cin >> item2.bookNo >> item2.units_sold >> price;
    item2.revenue = item2.units_sold * price;
    if (item1.bookNo == item2.bookNo) {
        Sales_data total;
        total.bookNo = item1.bookNo;
        total.units_sold = item1.units_sold + item2.units_sold;
        total.revenue = item1.revenue + item2.revenue;
        std::cout << total.bookNo << " "
                  << total.units_sold << " "
                  << total.revenue << " ";
        if (total.units_sold != 0) {
            std::cout << total.revenue / total.units_sold << std::endl;
        } else {
            std::cout << "No sales!" << std::endl;
        }
    } else {
        std::cerr << "Data must refer to same bookNo" << std::endl;
        return -1;
    }
    */

    //1.5.2
    /*
    std::cout << "1.5.2" << std::endl;
    Sales_data total;
    price = 0.0;
    if (std::cin >> total.bookNo >> total.units_sold >> price) {
        total.revenue = total.units_sold * price;
        Sales_data trans;
        price = 0.0;
        while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue = trans.units_sold * price;
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                std::cout << total.bookNo << " "
                          << total.units_sold << " "
                          << total.revenue << " ";
                if (total.units_sold != 0) {
                    std::cout << total.revenue / total.units_sold << std::endl;
                } else {
                    std::cout << "No sales" << std::endl;
                }
                total = trans;
            }
        }
        std::cout << total.bookNo << " "
                  << total.units_sold << " "
                  << total.revenue << " ";
        if (total.units_sold != 0) {
            std::cout << total.revenue / total.units_sold << std::endl;
        } else {
            std::cout << "No sales" << std::endl;
        }
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    */

    //exercise_1_23
    std::cout << "exercise_1_23" << std::endl;
    Sales_data test1;
    double price = 0.0;
    if (std::cin >> test1.bookNo >> test1.units_sold >> price) {
        test1.revenue = test1.units_sold * price;
        int cnt = 1;
        Sales_data trans;
        while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue = trans.units_sold * price;
            if (test1.bookNo == trans.bookNo) {
                ++cnt;
            } else {
                std::cout << test1.bookNo << " has " << cnt << " transaction(s)" << std::endl;
                test1 = trans;
                cnt = 1;
            }
        }
        std::cout << test1.bookNo << " has " << cnt << " transaction(s)" << std::endl;
    }
    return 0;
}
