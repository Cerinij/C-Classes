#pragma once
#include <iostream>
using namespace std;

class Pair
{
    int first;
    double second;
public:
    Pair(int f = 0, double s = 0.0) : first(f), second(s) {}

    Pair operator+(const Pair& other) const
    {
        return Pair(first + other.first, second + other.second);
    }

    Pair operator/(int n) const
    {
        return Pair(first / n, second / n);
    }

    Pair operator*(const Pair& other) const
    {
        return Pair(first * other.first, second * other.second);
    }

    bool operator==(const Pair& other) const
    {
        return (first == other.first && second == other.second);
    }

    bool operator>=(const Pair& other) const
    {
        return (first > other.first) || (first == other.first && second >= other.second);
    }

    bool operator<=(const Pair& other) const
    {
        return (first < other.first) || (first == other.first && second <= other.second);
    }

    friend istream& operator>>(istream& in, Pair& p)
    {
        cout << "¬ведите целое и дробное число: ";
        in >> p.first >> p.second;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Pair& p)
    {
        out << "(" << p.first << ", " << p.second << ")";
        return out;
    }
};
