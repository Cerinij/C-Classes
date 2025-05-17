#include "List.h"
#include <iostream>
#include <clocale>
#include <windows.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    List a, b;

    cout << "Введите список a:" << endl;
    cin >> a;

    cout << "Введите список b:" << endl;
    cin >> b;

    cout << "Список a: " << a << endl;
    cout << "Список b: " << b << endl;

    List c = a * b;
    cout << "Результат умножения списков: " << c << endl;

    cout << "Размер списка a: " << a() << endl;
    cout << "a[1] = " << a[1] << endl;

    Iterator it = a.begin();
    it = it + 2;
    cout << "Элемент a[2] (через итератор): " << *it << endl;

    cout << "Вывод списка a через итератор:" << endl;
    for (Iterator i = a.begin(); i != a.end(); ++i)
        cout << *i << " ";

    return 0;
}
