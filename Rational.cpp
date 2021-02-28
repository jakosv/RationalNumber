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
    _nan = (_denumerator == 0);
}

Rational Rational::neg() const {
    return Rational(-1*_numerator, _denumerator);
}

Rational Rational::inv() const {
    if (_numerator < 0) {
        return Rational(-_denumerator, -_numerator);
    }
    else {
        return Rational(_denumerator, _numerator);
    }
}

Rational Rational::reduce() const {
    int sign = 1;
    if (_numerator < 0) {
        sign = -1;
    }
    int d = 1;
    if (!_nan) {
        d = gcd(sign * _numerator, _denumerator); 
    }
    return Rational(_numerator / d, _denumerator / d);
}

Rational Rational::sum(const Rational& other) const {
    int num1, num2;
    num1 = _numerator;
    num2 = other._numerator;
    int newDenumerator;
    if (_denumerator == 0 || other._denumerator == 0) {
        newDenumerator = 0;
        num1 = 0;
        num2 = 1;
    }
    else {
        newDenumerator = lcm(_denumerator, other._denumerator);
        num1 *= newDenumerator / _denumerator;
        num2 *= newDenumerator / other._denumerator;
    }
    Rational res(num1 + num2, newDenumerator);

    return res.reduce();
}

Rational Rational::sub(const Rational& other) const {
    return sum(other.neg());
}

Rational Rational::mul(const Rational& other) const {
    Rational res(_numerator * other._numerator,
                 _denumerator * other._denumerator);
    
    return res.reduce();
}

Rational Rational::div(const Rational& other) const {
    return mul(other.inv());
}

Rational Rational::operator+(const Rational& other) const {
    return sum(other);
}

Rational Rational::operator-(const Rational& other) const {
    return sub(other);
}

Rational Rational::operator*(const Rational& other) const {
    return mul(other);
}

Rational Rational::operator/(const Rational& other) const {
    return div(other);
}

bool Rational::equal(const Rational& other) const {
    Rational res = *this - other;
    return (res._numerator == 0 && !(_nan || other._nan));
}

bool Rational::notEqual(const Rational& other) const {
    std::cout << other._nan << " " << _nan << std::endl;
    return (!equal(other) && !(_nan || other._nan));
}

bool Rational::less(const Rational& other) const {
    Rational res = *this - other;
    return (res._numerator < 0 && !(_nan || other._nan));
}

bool Rational::lessOrEqual(const Rational& other) const {
    return ((this->less(other) || this->equal(other)) 
            && !(_nan || other._nan));
}

bool Rational::greater(const Rational& other) const {
    return (!this->lessOrEqual(other) && !(_nan || other._nan));
}

bool Rational::greaterOrEqual(const Rational& other) const {
    return (!this->less(other) && !(_nan || other._nan));
}

bool Rational::operator<(const Rational& other) const {
    return less(other);    
}

bool Rational::operator>(const Rational& other) const {
    return greater(other);
}

bool Rational::operator<=(const Rational& other) const {
    return lessOrEqual(other);
}

bool Rational::operator>=(const Rational& other) const {
    return greaterOrEqual(other);
}

bool Rational::operator==(const Rational& other) const {
    return equal(other);
}
    
bool Rational::operator!=(const Rational& other) const {
    return notEqual(other);
}
