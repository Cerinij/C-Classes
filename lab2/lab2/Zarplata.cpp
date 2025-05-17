#include "Zarplata.h"


Zarplata::Zarplata()
{
    fio = "";
    oklad = 0;
    premiya_percent = 0;
    cout << "����������� ��� ���������� ��� �������: " << this << endl;
}

Zarplata::Zarplata(string f, double o, int p)
{
    fio = f;
    oklad = o;
    premiya_percent = p;
    cout << "����������� � ����������� ��� �������: " << this << endl;
}

Zarplata::Zarplata(const Zarplata& z)
{
    fio = z.fio;
    oklad = z.oklad;
    premiya_percent = z.premiya_percent;
    cout << "����������� ����������� ��� �������: " << this << endl;
}

Zarplata::~Zarplata()
{
    cout << "���������� ��� �������: " << this << endl;
}

string Zarplata::get_fio() { return fio; }
double Zarplata::get_oklad() { return oklad; }
int Zarplata::get_premiya_percent() { return premiya_percent; }

void Zarplata::set_fio(string f) { fio = f; }
void Zarplata::set_oklad(double o) { oklad = o; }
void Zarplata::set_premiya_percent(int p) { premiya_percent = p; }

void Zarplata::show()
{
    cout << "���: " << fio << endl;
    cout << "�����: " << oklad << endl;
    cout << "������ (%): " << premiya_percent << "%" << endl;
    cout << "����� � �������: " << oklad + (oklad * premiya_percent / 100.0) << endl;
}
