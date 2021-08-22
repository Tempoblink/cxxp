#pragma once

#include <istream>
#include <ostream>
#include <string>
#include <type_traits>


class Sales_data {
    friend std::ostream &operator<<(std::ostream &, const Sales_data &);
    friend std::istream &operator>>(std::istream &, Sales_data &);
    friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
    friend bool operator<(const Sales_data &lhs, const Sales_data &rhs);
    friend bool operator>(const Sales_data &lhs, const Sales_data &rhs);
    friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
    friend bool operator!=(const Sales_data &lhs, const Sales_data &rhs);

public:
    Sales_data() = default;
    Sales_data(const std::string &name) : bookNo(name) {}
    Sales_data(const Sales_data &book) : bookNo(book.bookNo), units_sold(book.units_sold), revenue(book.revenue) {}
    Sales_data(Sales_data &&book) noexcept
        : bookNo(std::move(book.bookNo)), units_sold(std::move(book.units_sold)), revenue(std::move(book.revenue)) {}
    ~Sales_data() = default;

    explicit operator std::string() const {
        return isbn() + " " + std::to_string(units_sold) + " " + std::to_string(avg_price()) + " " + std::to_string(revenue);
    }
    explicit operator double() const {
        return revenue;
    }

    Sales_data &
    operator=(Sales_data);
    Sales_data &operator=(const std::string &);
    Sales_data &operator+=(const Sales_data &);
    void swap(Sales_data &lhs, Sales_data &rhs);
    std::string isbn() const { return bookNo; }

private:
    Sales_data &combine(const Sales_data &);
    double avg_price() const {
        if (units_sold) return revenue / units_sold;
        return 0;
    }
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
