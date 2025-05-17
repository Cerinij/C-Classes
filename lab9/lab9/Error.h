#pragma once
#include <iostream>
using namespace std;

class Error
{
public:
    virtual void what() {};
};

class IndexError : public Error
{
public:
    void what() override
    {
        cout << "Ошибка: индекс выходит за границы списка" << endl;
    }
};

class SizeMismatch : public Error
{
public:
    void what() override
    {
        cout << "Ошибка: размеры списков не совпадают для умножения" << endl;
    }
};

class RangeError : public Error
{
public:
    void what() override
    {
        cout << "Ошибка: переход по индексу невозможен" << endl;
    }
};
