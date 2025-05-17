#pragma once
#include "Object.h"

class Vector
{
protected:
    Object** beg;
    int size;
    int cur;
public:
    Vector(int = 10);
    virtual ~Vector();
    void Add();
    void Del();
    void Show();
    int operator()();
    virtual void HandleEvent(const TEvent& e);
};
