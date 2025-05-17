#pragma once
#include "Person.h"

class Vector
{
public:
    Vector();
    Vector(int);
    ~Vector();

    void Add(Person*);
    friend ostream& operator<<(ostream&, const Vector&);

private:
    Person** beg;
    int size;
    int cur;
};
