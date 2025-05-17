#include "Student.h"
#include <iostream>
#include <clocale>
#include <windows.h>
using namespace std;

void f1(Person& p)
{
    p.set_name("Имя");
    p.set_age(99);
    cout << "Объект внутри f1():" << endl << p;
}

Person f2()
{
    Student s("Иван", 18, "Математика", 2);
    return s;
}

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Student s1;
    cin >> s1;
    cout << s1;
    s1.check_mark();

    cout << endl << "Принцип подстановки:" << endl;
    f1(s1);
    Person p = f2();
    cout << "Результат f2():" << endl << p;

    return 0;
}
