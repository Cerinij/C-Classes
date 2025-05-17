#pragma once
#include <iostream>
using namespace std;

class Pair
{
    int first;
    double second;

public:
    Pair();
    Pair(int f, double s);
    Pair(const Pair& p);
    ~Pair();

    int get_first() const;
    double get_second() const;
    void set_first(int f);
    void set_second(double s);

    Pair& operator=(const Pair& p);
    Pair operator-(const Pair& p) const;

    Pair operator+(int val) const;
    Pair operator+(double val) const;

    friend istream& operator>>(istream& in, Pair& p);
    friend ostream& operator<<(ostream& out, const Pair& p);
};
