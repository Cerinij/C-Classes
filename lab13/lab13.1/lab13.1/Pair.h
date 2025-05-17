#pragma once
#include <iostream>
using namespace std;

class Pair
{
public:
    int first;
    double second;

    Pair(int f = 0, double s = 0.0) : first(f), second(s) {}

    Pair operator+(const Pair& other) const
    {
        return Pair(first + other.first, second + other.second);
    }

    Pair operator/(int n) const {
        return Pair(first / n, second / n);
    }


    bool operator<(const Pair& other) const
    {
        return (first < other.first) || (first == other.first && second < other.second);
    }

    bool operator>(const Pair& other) const
    {
        return (first > other.first) || (first == other.first && second > other.second);
    }

    bool operator>=(const Pair& other) const { return !(*this < other); }
    bool operator<=(const Pair& other) const { return !(*this > other); }

    Pair& operator+=(const Pair& other)
    {
        first += other.first;
        second += other.second;
        return *this;
    }

    friend istream& operator>>(istream& in, Pair& p)
    {
        cout << "¬ведите целую и дробную часть: ";
        in >> p.first >> p.second;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Pair& p)
    {
        out << "(" << p.first << ", " << p.second << ")";
        return out;
    }
};
