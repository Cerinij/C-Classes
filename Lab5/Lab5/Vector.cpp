#include "Vector.h"

Vector::Vector() : beg(nullptr), size(0), cur(0) {}
Vector::Vector(int n) : size(n), cur(0)
{
    beg = new Person * [n];
}
Vector::~Vector()
{
    if (beg) delete[] beg;
}

void Vector::Add(Person* p)
{
    if (cur < size)
    {
        beg[cur++] = p;
    }
}

ostream& operator<<(ostream& out, const Vector& v)
{
    if (v.size == 0)
    {
        out << "Вектор пуст." << endl;
        return out;
    }
    for (int i = 0; i < v.cur; i++)
    {
        v.beg[i]->Show();
    }
    return out;
}
