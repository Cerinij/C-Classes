#include "List.h"
#include "Error.h"
#include <clocale>
#include <iostream>
#include <exception>
using namespace std;

void F();

int main()
{
    setlocale(LC_ALL, "ru");
    set_terminate(F);
    set_unexpected(F);

    List a(5), b(5), c(6);
    cout << "Введите элементы списка a:" << endl;
    cin >> a;
    cout << "Введите элементы списка b:" << endl;
    cin >> b;
    cout << "Введите элементы списка c:" << endl;
    cin >> c;
    cout << endl << "Список a: " << a;
    cout << "Список b: " << b;
    cout << "Список с: " << c;

    try
    {
        cout << endl << "Поэлементное умножение a * b:" << endl;
        List d = a * b;
        cout << d;
    }
    catch (Error& e)
    {
        e.what();
    }
    catch (exception& e)
    {
        cout << "Стандартное исключение: " << e.what() << endl;
    }


    try
    {
        cout << "Введите индекс для доступа (a[index]): ";
        int i;
        cin >> i;
        cout << "Значение a[" << i << "] = " << a[i] << endl;
    }
    catch (Error& e)
    {
        e.what();
    }
    catch (exception& e)
    {
        cout << "Стандартное исключение: " << e.what() << endl;
    }

    int i;
    cout << "Введите индекс списка а: ";
    cin >> i;
    cout << "Значение: " << (a + i) << endl;

    try
    {
        cout << endl << "Поэлементное умножение a * c:" << endl;
        List e = a * c;
    }
    catch (Error& e)
    {
        e.what();
    }
    catch (exception& e)
    {
        cout << "Стандартное исключение: " << e.what() << endl;
    }

    return 0;
}
