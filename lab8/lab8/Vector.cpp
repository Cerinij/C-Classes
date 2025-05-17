#include "Vector.h"
#include "Magazine.h"
#include <iostream>
using namespace std;

Vector::Vector(int s)
{
    size = s;
    beg = new Object * [size];
    cur = 0;
}

Vector::~Vector()
{
    if (beg) delete[] beg;
    beg = nullptr;
}

void Vector::Add()
{
    Object* p;
    p = new Magazine;
    p->Input();
    if (cur < size)
    {
        beg[cur++] = p;
    }
}

void Vector::Del() {
    if (cur > 0) cur--;
}

void Vector::Show()
{
    if (cur == 0) cout << "Empty" << endl;
    for (int i = 0; i < cur; i++)
    {
        beg[i]->Show();
    }
}

int Vector::operator()()
{
    return cur;
}

void Vector::HandleEvent(const TEvent& e)
{
    if (e.what == evMessage)
    {
        for (int i = 0; i < cur; i++)
        {
            beg[i]->HandleEvent(e);
        }
    }
}
