#pragma once
#include "Node.h"
#include "Iterator.h"
#include <iostream>
using namespace std;

class List
{
    Node* head;
    int size;

public:
    List();
    List(const List&);
    ~List();

    List& operator=(const List&);
    int& operator[](int index);
    int operator()() const;
    List operator*(const List&) const;
    friend istream& operator>>(istream&, List&);
    friend ostream& operator<<(ostream&, const List&);

    Iterator begin() const;
    Iterator end() const;

    void push_back(int);
};
