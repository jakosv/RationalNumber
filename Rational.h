#pragma once
#include <iostream>

int gcd(int x, int y);

class Rational {
private:
    bool _nan;
    int _numerator;
    int _denumerator;
public:

    Rational();
    Rational(const int x, const int y);
    Rational(const int x);
    Rational(const Rational& other);

    Rational reduce();
    Rational neg() const;
    Rational inv() const;

    Rational sum(const Rational& other);
    Rational sub(const Rational& other);
    Rational mul(const Rational& other);
    Rational div(const Rational& other);

    bool equal(const Rational& other);
    bool notEqual(const Rational& other);
    bool less(const Rational& other);
    bool lessOrEqual(const Rational& other);
    bool greater(const Rational& other);
    bool greaterOrEqual(const Rational& other);

    void print();
    void scan();

    Rational& operator=(const Rational& other);
    Rational& operator=(Rational&& other);
    bool operator<(const Rational& other);
    bool operator>(const Rational& other);
    bool operator<=(const Rational& other);
    bool operator>=(const Rational& other);
    bool operator==(const Rational& other);
    bool operator!=(const Rational& other);
    Rational operator+(const Rational& other);
    Rational operator-(const Rational& other);
    Rational operator*(const Rational& other);
    Rational operator/(const Rational& other);
};
