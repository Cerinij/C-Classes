#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE = 30;

class List
{
    int* data;
    int size;
public:
    List() : size(0), data(nullptr) {}
    List(int s);
    List(const List& other);
    ~List();
    List& operator=(const List& other);
    int operator[](int i);
    int operator()();
    List operator*(const List& other);
    int operator+(int index);
    friend ostream& operator<<(ostream& out, const List& l);
    friend istream& operator>>(istream& in, List& l);
};
