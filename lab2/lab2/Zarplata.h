#pragma once
#include <iostream>
#include <string>
using namespace std;

class Zarplata
{
    string fio;
    double oklad;
    int premiya_percent;

public:
    Zarplata();
    Zarplata(string, double, int);
    Zarplata(const Zarplata&);
    ~Zarplata();

    string get_fio();
    double get_oklad();
    int get_premiya_percent();

    void set_fio(string);
    void set_oklad(double);
    void set_premiya_percent(int);

    void show();
};
