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

    Rational reduce() const;
    Rational neg() const;
    Rational inv() const;

    Rational sum(const Rational& other) const;
    Rational sub(const Rational& other) const;
    Rational mul(const Rational& other) const;
    Rational div(const Rational& other) const;

    bool equal(const Rational& other) const;
    bool notEqual(const Rational& other) const;
    bool less(const Rational& other) const;
    bool lessOrEqual(const Rational& other) const;
    bool greater(const Rational& other) const;
    bool greaterOrEqual(const Rational& other) const;

    void print();
    void scan();

    Rational& operator=(const Rational& other);
    Rational& operator=(Rational&& other);
    bool operator<(const Rational& other) const;
    bool operator>(const Rational& other) const;
    bool operator<=(const Rational& other) const;
    bool operator>=(const Rational& other) const;
    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;
    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;
};
