#pragma once
#include <iostream>
using namespace std;

class Pair
{
    int first;
    double second;
public:
    Pair(int f = 0, double s = 0.0) : first(f), second(s) {}
    Pair(const Pair& p) : first(p.first), second(p.second) {}

    Pair operator*(const Pair& other) const
    {
        return Pair(first * other.first, second * other.second);
    }

    Pair& operator=(const Pair& other)
    {
        first = other.first;
        second = other.second;
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Pair& p)
    {
        out << p.first << ":" << p.second;
        return out;
    }

    friend istream& operator>>(istream& in, Pair& p)
    {
        cout << "¬ведите целую часть: ";
        in >> p.first;
        cout << "¬ведите вещественную часть: ";
        in >> p.second;
        return in;
    }
};
