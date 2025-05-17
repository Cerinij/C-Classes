#include "Pair.h"

Pair::Pair() : first(0), second(0.0) {}
Pair::Pair(int f, double s) : first(f), second(s) {}
Pair::Pair(const Pair& p) : first(p.first), second(p.second) {}
Pair::~Pair() {}

int Pair::get_first() const { return first; }
double Pair::get_second() const { return second; }
void Pair::set_first(int f) { first = f; }
void Pair::set_second(double s) { second = s; }

Pair& Pair::operator=(const Pair& p)
{
    if (this == &p) return *this;
    first = p.first;
    second = p.second;
    return *this;
}

Pair Pair::operator-(const Pair& p) const
{
    return Pair(first - p.first, second - p.second);
}

Pair Pair::operator+(int val) const
{
    return Pair(first + val, second);
}

Pair Pair::operator+(double val) const
{
    return Pair(first, second + val);
}

istream& operator>>(istream& in, Pair& p)
{
    cout << "¬ведите первое число: ";
    in >> p.first;
    cout << "¬ведите второе число: ";
    in >> p.second;
    return in;
}

ostream& operator<<(ostream& out, const Pair& p)
{
    out << p.first << " : " << p.second;
    return out;
}
