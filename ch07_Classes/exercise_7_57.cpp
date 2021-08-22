/*
 * 编写你自己的Account类。
 */

#include <iostream>
#include <string>

class Accout {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);

private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
};

void Accout::rate(double newRate) {
    interestRate = newRate;
}

double Accout::initRate() {
    return 2.0;
}

double Accout::interestRate = initRate();

int main(void) {
    double r = Accout::rate();
    std::cout << "r = " << r << std::endl;
    return 0;
}
