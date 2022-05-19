#include "Rational.h"
#include <iostream>
#include <sstream>

Rational::Rational(int a, int b) throw(MyException)
{
    setA(a);
    if (b == 0)
        throw new MyException("b == 0");
    setB(b);
    Reduce();
}

Rational::Rational(const Rational& r)
{
    *this = r;
}

Rational& Rational::operator=(const Rational& r)
{
    a = r.a;
    b = r.b;
    return *this;
}

void Rational::setB(int _b) throw(RationalException)
{
    if (_b == 0)
        throw RationalException("b == 0");
}

Rational::operator string() const
{
    stringstream ss;
    ss << a << '/' << b;
    return ss.str();
}

Rational& Rational::operator++()
{
    a++;
    return *this;
}

Rational& Rational::operator--()
{
    a--;
    return *this;
}

Rational Rational::operator++(int)
{
    Rational r(*this);
    a++;
    return r;
}

Rational Rational::operator--(int)
{
    Rational r(*this);
    a++;
    return r;
}

void Rational::Reduce()
{
    int i;
    do {
        for (i = abs(std::min(a, b)); i > 0; i--)
        {
            if (a % i == 0 && b % i == 0) {
                a /= i;
                b /= i;
                break;
            }
        }
    } while (i != 1);
}

ostream& operator<<(ostream& out, const Rational& r)
{
    out << (string)r;
    return out;
}

istream& operator>>(istream& in, Rational& r)
{
    cout << "Чисельник: "; cin >> r.a;
    cout << "Знаменник: "; cin >> r.b;
    if (r.b == 0)
        throw exception("b == 0");
    return in;
}

Rational operator/(const Rational& r1, const Rational& r2)
{
    Rational r;
    r.a = r1.a * r2.b;
    r.b = r2.a * r1.b;
    r.Reduce();
    return Rational(r);
}

bool operator==(const Rational& r1, const Rational& r2)
{
    auto r11 = r1, r22 = r2;
    r11.Reduce();
    r22.Reduce();
    return r11.a == r22.a && r11.b == r22.b;
}

bool operator<(const Rational& r1, const Rational& r2)
{
    auto r11 = r1, r22 = r2;
    r11.Reduce();
    r22.Reduce();
    return r11.value() < r22.value();
}

bool operator>(const Rational& r1, const Rational& r2)
{
    auto r11 = r1, r22 = r2;
    r11.Reduce();
    r22.Reduce();
    return r11.value() > r22.value();
}
