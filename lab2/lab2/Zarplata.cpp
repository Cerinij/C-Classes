#include "Zarplata.h"


Zarplata::Zarplata()
{
    fio = "";
    oklad = 0;
    premiya_percent = 0;
    cout << "Конструктор без параметров для объекта: " << this << endl;
}

Zarplata::Zarplata(string f, double o, int p)
{
    fio = f;
    oklad = o;
    premiya_percent = p;
    cout << "Конструктор с параметрами для объекта: " << this << endl;
}

Zarplata::Zarplata(const Zarplata& z)
{
    fio = z.fio;
    oklad = z.oklad;
    premiya_percent = z.premiya_percent;
    cout << "Конструктор копирования для объекта: " << this << endl;
}

Zarplata::~Zarplata()
{
    cout << "Деструктор для объекта: " << this << endl;
}

string Zarplata::get_fio() { return fio; }
double Zarplata::get_oklad() { return oklad; }
int Zarplata::get_premiya_percent() { return premiya_percent; }

void Zarplata::set_fio(string f) { fio = f; }
void Zarplata::set_oklad(double o) { oklad = o; }
void Zarplata::set_premiya_percent(int p) { premiya_percent = p; }

void Zarplata::show()
{
    cout << "ФИО: " << fio << endl;
    cout << "Оклад: " << oklad << endl;
    cout << "Премия (%): " << premiya_percent << "%" << endl;
    cout << "Итого с премией: " << oklad + (oklad * premiya_percent / 100.0) << endl;
}
