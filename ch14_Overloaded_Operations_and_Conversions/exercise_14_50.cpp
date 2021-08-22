/*
 * 在初始化ex1和ex2的过程中，可能用到哪些类类型的转换序列呢？
 * 说明初始化是否正确并解释原因。
 * struct LongDouble {
 *      LongDouble(double = 0.0);
 *      operator double();
 *      operator float();
 * };
 * LongDouble ldObj;
 * int ex1 = ldObj;
 * float ex2 = ldObj;
 */

#include <iostream>

struct LongDouble {
    LongDouble(const double &i = 0.0) : x(i) {}
    operator double() {
        std::cout << "double()" << std::endl;
        return x;
    }
    operator float() {
        std::cout << "float()" << std::endl;
        return x;
    }

private:
    double x;
};

int main(int argc, char const *argv[]) {
    LongDouble ldObj;
    // int ex1 = ldObj;  //error: conversion from 'LongDouble' to 'int' is ambiguous
    float ex2 = ldObj;
    return 0;
}
