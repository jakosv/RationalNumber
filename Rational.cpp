#include "Rational.h"

int gcd(int x, int y) {
    while (y != 0) {
        x %= y;
        std::swap(x, y);
    }
    return x;
}

int lcm(int x, int y) {
    return x / gcd(x, y) * y;
}

Rational::Rational() {
    _numerator = 1;
    _denumerator = 1;
    _nan = false;
}

Rational::Rational(const int x, const int y) {
    _numerator = x;
    _denumerator = y;
    _nan = (y == 0);
}

Rational::Rational(const int x) {
    _numerator = x;
    _denumerator = 1;
    _nan = false;
}

Rational::Rational(const Rational& other) {
    _numerator = other._numerator;
    _denumerator = other._denumerator;
    _nan = other._nan;
}

Rational& Rational::operator=(const Rational& other) {
    _numerator = other._numerator;
    _denumerator = other._denumerator;
    _nan = other._nan;
}

Rational& Rational::operator=(Rational&& other) {
    _numerator = other._numerator;
    _denumerator = other._denumerator;
    _nan = other._nan;
}

void Rational::print() {
    if (_nan) {
        std::cout << "NaN" << std::endl;
    }
    else {
        std::cout 
            << _numerator
            << "/"
            << _denumerator
            << std::endl;
    }
}

void Rational::scan() {
    char c;
    std::cin >> _numerator >> c >> _denumerator;
}

Rational Rational::neg() {
    return Rational(-1*_numerator, _denumerator);
}


Rational Rational::inv() {
    if (_numerator < 0) {
        return Rational(-_denumerator, -_numerator);
    }
    else {
        return Rational(_denumerator, _numerator);
    }
}

Rational Rational::reduce() {
    int sign = 1;
    if (_numerator < 0) {
        sign = -1;
        _denumerator = -_denumerator;
    }
    int d = 1;
    if (!_nan) {
        d = gcd(_numerator, _denumerator); 
    }
    return Rational(sign * _numerator / d, _denumerator / d);
}

Rational Rational::sum(Rational other) {
    int num1, num2;
    num1 = _numerator;
    num2 = other._numerator;
    int newDenumerator = lcm(_denumerator, other._denumerator);
    if (_denumerator == 0 || other._denumerator == 0) {
        newDenumerator = 0;
        num1 = 1;
        num2 = 0;
    }
    else {
        num1 *= newDenumerator / _denumerator;
        num2 *= newDenumerator / other._denumerator;
    }
    Rational res(num1 + num2, newDenumerator);

    return res.reduce();
}

Rational Rational::sub(Rational other) {
    return sum(other.neg());
}

Rational Rational::mul(Rational other) {
    Rational res(_numerator * other._numerator,
                 _denumerator * other._denumerator);
    
    return res.reduce();
}

Rational Rational::div(Rational other) {
    return mul(other.inv());
}

Rational Rational::operator+(const Rational& other) {
    return sum(other);
}

Rational Rational::operator-(const Rational& other) {
    return sub(other);
}

Rational Rational::operator*(const Rational& other) {
    return mul(other);
}

Rational Rational::operator/(const Rational& other) {
    return div(other);
}

bool Rational::equal(const Rational& other) {
    Rational res = *this - other;
    return (res._numerator == 0);
}

bool Rational::notEqual(const Rational& other) {
    return !equal(other);
}

bool Rational::less(const Rational& other) {
    Rational res = *this - other;
    return (res._numerator < 0);
}

bool Rational::lessOrEqual(const Rational& other) {
    return (this->less(other) || this->equal(other));
}

bool Rational::greater(const Rational& other) {
    return !this->lessOrEqual(other);
}

bool Rational::greaterOrEqual(const Rational& other) {
    return !this->less(other);
}

bool Rational::operator<(const Rational& other) {
    return less(other);    
}

bool Rational::operator>(const Rational& other) {
    return greater(other);
}

bool Rational::operator<=(const Rational& other) {
    return lessOrEqual(other);
}

bool Rational::operator>=(const Rational& other) {
    return greaterOrEqual(other);
}

bool Rational::operator==(const Rational& other) {
    return equal(other);
}
    
bool Rational::operator!=(const Rational& other) {
    return notEqual(other);
}
