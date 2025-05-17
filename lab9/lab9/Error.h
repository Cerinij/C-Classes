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
        cout << "������: ������ ������� �� ������� ������" << endl;
    }
};

class SizeMismatch : public Error
{
public:
    void what() override
    {
        cout << "������: ������� ������� �� ��������� ��� ���������" << endl;
    }
};

class RangeError : public Error
{
public:
    void what() override
    {
        cout << "������: ������� �� ������� ����������" << endl;
    }
};
