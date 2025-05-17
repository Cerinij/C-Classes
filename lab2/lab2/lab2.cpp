#include "Zarplata.h"
#include <iostream>
#include <clocale>
#include <windows.h>
using namespace std;

Zarplata make_zarplata()
{
    string fio;
    double oklad;
    int premiya;

    cout << "Введите ФИО: ";
    cin >> ws;
    getline(cin, fio);
    cout << "Введите оклад: ";
    cin >> oklad;
    cout << "Введите премию (%): ";
    cin >> premiya;

    Zarplata z(fio, oklad, premiya);
    return z;
}

void print_zarplata(Zarplata z)
{
    z.show();
}

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Zarplata z1;
    z1.show();

    Zarplata z2("Иванов Иван Иванович", 70000, 20);
    z2.show();

    Zarplata z3 = z2;
    z3.set_fio("Семёнов Семён Семёнович");
    z3.set_oklad(80000);
    z3.set_premiya_percent(25);

    print_zarplata(z3);

    z1 = make_zarplata();
    z1.show();

    return 0;
}
